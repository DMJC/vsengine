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
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

package vegamap;

import java.io.File;
import java.io.FileInputStream;
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
import vegamap.exception.GalaxyLoadException;

public class Galaxy {
    
    private Map<String, GalaxySector> sectors;
    
    public Galaxy(File file) throws GalaxyLoadException {
        sectors = new Hashtable<String, GalaxySector>();
        
        FileInputStream input = null;
        
        try {
            input = new FileInputStream(file);
        } catch (Exception e) {
            throw new GalaxyLoadException(e);
        }
        
        loadGalaxy(input);
        resolveJumps();
    }
    
    private void loadGalaxy(InputStream is) throws GalaxyLoadException {
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
        
        Element systemsElement = (Element)systemList.item(0);
        
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
        
        GalaxySystem system = new GalaxySystem(name, pos, faction);
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
    
    public static void main(String[] args) {
        Galaxy gal = null;
        
        try {
            gal = new Galaxy(new File("milky_way.xml"));
        } catch (GalaxyLoadException e) {
            e.printStackTrace();
            return;
        }
        
        List<GalaxySector> sectors = gal.getSectors();
        for (GalaxySector sector : sectors) {
            System.out.println(sector.getName());
            
            for (GalaxySystem system : sector.getSystems()) {
                System.out.println("\t" + system.getName() + "/" + system.getFaction());
            }
        }
    }
    
}
