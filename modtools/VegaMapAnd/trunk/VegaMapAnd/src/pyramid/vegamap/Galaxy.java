/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 */

package pyramid.vegamap;

import java.io.File;
import java.io.FileInputStream;
import java.io.DataInputStream;
import java.io.InputStream;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;
import java.util.Vector;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import android.content.Context;
import android.content.res.AssetManager;
import android.os.Environment;

import pyramid.vegamap.exception.GalaxyLoadException;
import android.util.Log;

public class Galaxy {
    
    public final String DATA_DIR = "/data/";
	
	public GalaxySystems systems;
	public GalaxyJumps jumpNetwork;
	public GalaxyFaction faction;
	public String name;
	
	private Context mContext;
    private Map<String, GalaxySector> sectors;
	private String baseDir;
    
    public Galaxy(String sMapName, boolean bUseExtDir) throws GalaxyLoadException {
		mContext = VegaMapAnd.context;
        sectors = new Hashtable<String, GalaxySector>();
		jumpNetwork = new GalaxyJumps();
        faction = new GalaxyFaction();
		systems = new GalaxySystems();
		baseDir = Environment.getExternalStorageDirectory() + DATA_DIR + mContext.getPackageName() + File.separator;
		name = sMapName;
		
		DataInputStream in = null;
		if (bUseExtDir) {
			try {
				in = new DataInputStream(new FileInputStream(new File(baseDir+sMapName)));
			} catch (Exception e) {
				throw new GalaxyLoadException(e);
			}
        }
		if (!bUseExtDir) {
	        try {
				AssetManager am = mContext.getAssets();
				InputStream uStream = am.open("maps/"+sMapName, AssetManager.ACCESS_BUFFER);
				in = new DataInputStream(uStream); // Get around Java's stupid unsigned bytes 
			} catch (Exception e) {
                Log.e(this.getClass().getName(), "cannot decode bitmap");
				e.printStackTrace();
	        }
		}

		// testing and profiling info commented out for release
        //long time = System.currentTimeMillis();
        loadGalaxy(in);
        //Log.i(this.getClass().getName(), "load time: " + (System.currentTimeMillis()-time));
        //time = System.currentTimeMillis();
        resolveJumps();
        //Log.i(this.getClass().getName(), "resolve time: " + (System.currentTimeMillis()-time));
 
 		systems.makeSystems(this);
        //time = System.currentTimeMillis();
        jumpNetwork.makeJumps(this);
        //Log.i(this.getClass().getName(), "jump make time: " + (System.currentTimeMillis()-time));

        // performance measurement results
        // initial (PGG, res): l=984 ; r=1063
        // initial (VSU, res): l=6057 ; r=52402
        // traditional add jumps (VSU, res): l=6062 ; r=503
        // threaded add jumps (VSU, res): l=6020 ; r=563 ; m=1
}
    
    private void loadGalaxy(InputStream is) throws GalaxyLoadException {
        //Log.i(this.getClass().getName(), "--loadGalaxy");
        DocumentBuilderFactory factory = null;
        DocumentBuilder builder = null;
        Document doc = null;

        try {
            factory = DocumentBuilderFactory.newInstance();
            builder = factory.newDocumentBuilder();
            doc = builder.parse(is);
			is.close();
        } catch (Exception e) {
            throw new GalaxyLoadException(e);
        }

        Element element = doc.getDocumentElement();
        
        parseGalaxy(element);
        
    }
    
    private void parseGalaxy(Element element) throws GalaxyLoadException {
        if (!element.getNodeName().equals("galaxy")) {
            throw new GalaxyLoadException("Wrong root element name.");
        }
        
        NodeList systemList = element.getElementsByTagName("systems");
        if (systemList.getLength() != 1) {
            throw new GalaxyLoadException("Incorrect number of \"systems\"-nodes.");
        }
        
        NodeList sectorList = element.getElementsByTagName("sector");
        for (int i = 0; i < sectorList.getLength(); i++) {
            Element child = (Element)sectorList.item(i);
            
            parseSector(child);
        }
    }
    
    private void parseSector(Element element) {
        String name = element.getAttribute("name");
        
        if (name.equals("") || name.equals("unknown_sector")) {
            return;
        }
        
        NodeList systemList = element.getElementsByTagName("system");
        if (systemList.getLength() < 1) {
            return;
        }
        
        GalaxySector sector = new GalaxySector(name);
        
        for (int i = 0; i < systemList.getLength(); i++) {
            Element child = (Element)systemList.item(i);
            
            parseSystem(sector, child);
        }
        
        if (sector.getSystems().size() > 0) {
            sectors.put(name, sector);
        }
    }
    
    private void parseSystem(GalaxySector sector, Element element) {
        String name = element.getAttribute("name");
        
        if (name.equals("")) {
            return;
        }
        
        String xyz = "";
        String faction = "";
        String jumps = "";

        NodeList varList = element.getElementsByTagName("var");
        for (int i = 0; i < varList.getLength(); i++) {
            Element child = (Element)varList.item(i);
            
            String varName = child.getAttribute("name");
            
            if (varName.equals("xyz")) {
                xyz = child.getAttribute("value");
            }
            if (varName.equals("faction")) {
                faction = child.getAttribute("value");
            }
            if (varName.equals("jumps")) {
                jumps = child.getAttribute("value");
            }
        }
        
        Point3D pos = parsePos(xyz);
        if (pos == null) {
            return;
        }
        
        if (faction.equals("")) {
            faction = "unknown";
        }
        
        GalaxySystem system = new GalaxySystem(name, pos, faction, sector);
        if (jumps.length() > 0) {
            String[] parts = jumps.split(" ");
            for (int i = 0; i < parts.length; i++) {
                system.addJumpString(parts[i]);
            }
        }
        
        sector.addSystem(system);
    }
    
    private Point3D parsePos(String pos) {
        String[] parts = pos.split(" ");
        
        if (parts.length != 3) {
            return null;
        }
        
        try {
            double x = Double.parseDouble(parts[0]);
            double y = Double.parseDouble(parts[1]);
            double z = Double.parseDouble(parts[2]);

            return new Point3D(x, y, z);
        } catch (NumberFormatException e) {
            return null;
        }
    }
    
    public void resolveJumps() {
        for (GalaxySector sector : getSectors()) {
            for (GalaxySystem system : sector.getSystems()) {
                for (String jumpString : system.getJumpStrings()) {
                    String parts[] = jumpString.split("/");
                    
                    if (parts.length == 2) {
                        GalaxySector targetSector = getSector(parts[0]);
                        GalaxySystem targetSystem = targetSector.getSystem(parts[1]);
                        
                        if (targetSystem != null) {
                            system.addJump(targetSystem);
                        }
                    }
                }
                system.clearJumpStrings();
            }
        }
    }
    
    public List<GalaxySector> getSectors() {
        return new Vector<GalaxySector>(sectors.values());
    }
    
    public GalaxySector getSector(String name) {
        return sectors.get(name);
    }
    
    public void addSector(GalaxySector sector) {
        sectors.put(sector.getName(), sector);
    }
    
}
