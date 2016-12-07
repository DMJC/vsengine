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

import java.util.Hashtable;
import java.util.List;
import java.util.Map;

import javax.microedition.khronos.opengles.GL10;

import android.util.Log;

public class GalaxyView {

    // based on VegaMap
    // VERSION = "0.23 | 2011-03-23";

    public float center_x_min = 0;
    public float center_x_max = 0;
    public float center_y_min = 0;
    public float center_y_max = 0;
    public float centerX;
    public float centerY;
    public float universeSize;
	public float zoomFactor;
    public float moveX;
    public float moveY;
	public Point3D viewPortMin;
    public Point3D viewPortMax;
	public GLText font;
	public boolean bJumpsReady;
	public boolean bSystemsReady;
	public boolean bPathSelectMode = false;
    public GalaxySystems systems;

    private GL10 gl;
    private Galaxy galaxy;
	private GLSprite sprites;
	private GLDraw draw;
    private GalaxySystem start;
    private GalaxySystem end;
    private List<GalaxySystem> path;
    private PathFinder pathFinder;
    private Map<String, Boolean> flags;
	private GalaxyJumps jumps;
    
    private float starSize;
	private float scaleStarFont;
	private float scaleSectorFont;    
	
    public GalaxyView(GL10 gl, Galaxy galaxy, GLSprite sprites) {
        this.gl = gl;
        this.galaxy = galaxy;
		this.sprites = sprites;
        this.draw = new GLDraw();
        List<GalaxySector> sectors = this.galaxy.getSectors();
        viewPortMin = new Point3D(0,0,0);
        viewPortMax = new Point3D(0,0,0);
		jumps = galaxy.jumpNetwork;
		systems = galaxy.systems;
        
        // calculate map center
        for (GalaxySector sector : sectors) {
            for (GalaxySystem system : sector.getSystems()) {
                Point3D pos = system.getPos();
                center_x_min = Math.min((float)pos.x, center_x_min);
                center_x_max = Math.max((float)pos.x, center_x_max);
                center_y_min = Math.min((float)pos.y, center_y_min);
                center_y_max = Math.max((float)pos.y, center_y_max);
            }
        }
        centerX = center_x_min+(center_x_max-center_x_min)/2;
        centerY = center_y_min+(center_y_max-center_y_min)/2;
        universeSize = Math.max(center_x_max-center_x_min, center_y_max-center_y_min)/1000.0f;
        starSize =  4.0f/(float)Math.sqrt(1/universeSize);
		scaleSectorFont = 1.0f*universeSize;
        
        flags = new Hashtable<String, Boolean>();
        setFlag("show_jump_lines", false);
        setFlag("show_no_jumps", false);
        setFlag("show_sector_boxes", false);
        setFlag("show_system_name", false);
        setFlag("show_system_faction", false);
        setFlag("show_system_sector", false);
        setFlag("show_compass", false);
        setFlag("show_homeworlds", false);
		
        start = null;
        end = null;
        path = null;
        
        pathFinder = new PathFinder(galaxy);
    }

    public boolean getFlag(String name) {
        if (flags.containsKey(name)) {
            return flags.get(name);
        } else {
            return false;
        }
    }
    
    public void setFlag(String name, boolean value) {
        flags.put(name, value);
    }
    
    public void toggleFlag(String name) {
        setFlag(name, !getFlag(name));
    }
    
    //------------------------------------------
    // Universe Drawing Functions
    //------------------------------------------

    protected void paintComponent() {
        
		scaleStarFont = 0.45f*Math.max(0.3f,universeSize)/(float)Math.sqrt((double)zoomFactor);
        starSize =  4.0f/((float)Math.sqrt(1/universeSize)*(float)Math.sqrt(zoomFactor));
		bJumpsReady = jumps.bJumpsReady;
		bSystemsReady = systems.bSystemsReady;
		
        paintSystems();
        if (getFlag("show_homeworlds")) {
            paintHomeworlds();
        }
        if (getFlag("show_sector_boxes")) {
            paintSectorBoxes();
        }
        if (getFlag("show_sector_boxes")) {
            paintSectorNames();
        }
        if (getFlag("show_system_name") | getFlag("show_system_faction") | getFlag("show_system_sector")) {
            paintSystemNames();
        }
		if (getFlag("show_jump_lines")) {
			paintJumps();
		}        

        if (!bPathSelectMode | path!=null) {
            paintPath();
        }
    }

    public void paintSystems() {
        for (int i=0; i<systems.sysName.size(); i++) {
            try {
                String sectorname = systems.sysFullname.get(i).split("/")[0];
                String sysname = systems.sysName.get(i);
                GalaxySystem system = galaxy.getSector(sectorname).getSystem(sysname);
                if (system.hasJumps() || getFlag("show_no_jumps")) {
                    paintSystem(system);
                }
            } catch (Exception e) {
                Log.e(this.getClass().getName(), "cannot paint system");
                e.printStackTrace();              
            }
        }
        
        // always show selected systems on top
        if (start != null) {
            paintSystem(start);
        }
        if (path!=null) {
            paintSystem(end);
        }
    }
    
    private void paintSystem(GalaxySystem system) {
        
		float size;
        Point3D point = system.getPos();
		// restrict to visible stars
        if (point.x<viewPortMin.x | point.y<viewPortMin.y) {
            return;
        }
        if (point.x>viewPortMax.x | point.y>viewPortMax.y) {
            return;
        }
		
		// special size for dense VS sol cluster
		size = starSize;			
		if (galaxy.name.equals("vegastrike.xml")) {
			if (point.x>-22 & point.x<22 &
				point.y>-22 & point.y<22) {
				size = 0.2f*starSize;
			}
		}

        if (getFlag("show_no_jumps") & !system.hasJumps()) {
            sprites.drawSprite(gl, "spr_star_nojumps", new float[] {(float)point.getX(), (float)point.getY(), (float)point.getZ()}, size, 1.0f);
        } else {
            String sSprite = galaxy.faction.getFactionSpriteName(system.getFaction());
            if (sSprite==null) {
                sprites.drawSprite(gl, "spr_star_unknown", new float[] {(float)point.getX(), (float)point.getY(), (float)point.getZ()}, size, 1.0f);
            } else {
                sprites.drawSprite(gl, "spr_star_" + sSprite, new float[] {(float)point.getX(), (float)point.getY(), (float)point.getZ()}, size, 1.0f);
            }
        }
    }
    
    private void paintHomeworlds() {
        // Vega Strike species and faction home systems
        String[] HOMESYSTEMS = { "Sol", "Aeneilylk", "Gohdahru", "Regallis", "Bifrost", "Talos", "Kishar",
            "Mu_Ara", "Chang_cu", "Agea", "Palan", "Ea", "Ross248", "Kirov", "Spielberg", "Trotsky",
            "Cardell", "Hehet", "Bzzkabtl", "Izzahbtl", "Ptkabizz", "Zeenyqqh", "Zeen" };
        for (int i=0; i<systems.sysName.size(); i++) {
            String sysname = systems.sysName.get(i);
			for (int h=0; h<HOMESYSTEMS.length; h++) {
                if (sysname.equals(HOMESYSTEMS[h])) {
                    Point3D pos = systems.sysPos.get(i);
                    sprites.drawSprite(gl, "spr_planet", new float[] {(float)pos.x,(float)pos.y,(float)pos.z}, 0.5f*starSize/(float)Math.sqrt(zoomFactor), 1.0f);
                }
            }
        }
    }
	
    private void paintJump(GalaxySystem sys1, GalaxySystem sys2) {
		for (int i=0; i<jumps.jumpRoute.size(); i++) {
			Point3D pos1 = sys1.getPos();        
			Point3D pos2 = sys2.getPos();
			draw.drawLine(gl, pos1, pos2, new Color4f(1.0f,0.3f,0.3f,1.0f), 2);     
		}
    }
	
    private void paintJumps() {
		for (int i=0; i<jumps.jumpRoute.size(); i++) {
			Point3D pos1 = jumps.syspos1.get(i);        
			Point3D pos2 = jumps.syspos2.get(i);
			if ((pos1.x<viewPortMin.x | pos1.y<viewPortMin.y) & (pos2.x<viewPortMin.x | pos2.y<viewPortMin.y)) {
				continue;
			}
			if ((pos1.x>viewPortMax.x | pos1.y>viewPortMax.y) & (pos2.x>viewPortMin.x | pos2.y>viewPortMin.y) ) {
				continue;
			}
			draw.drawLine(gl, pos1, pos2, new Color4f(0.3f,0.3f,0.3f,1.0f));     
		}
    }

    private void paintSectorBoxes() {
        Color4f col = new Color4f(1.0f,0.5f,0f,1f);
        for (GalaxySector sector : galaxy.getSectors()) {
            Point3D min = sector.getMin();
            Point3D max = sector.getMax();
			if ((min.x<viewPortMin.x | min.y<viewPortMin.y) & (max.x<viewPortMin.x | max.y<viewPortMin.y)) {
				continue;
			}
			if ((min.x>viewPortMax.x | min.y>viewPortMax.y) & (max.x>viewPortMin.x | max.y>viewPortMin.y) ) {
				continue;
			}
			
			Point3D to = new Point3D(min.getX(), max.getY(), min.getZ());
			draw.drawLine(gl, min, to, col);     

			to = new Point3D(max.getX(), min.getY(), min.getZ());
			draw.drawLine(gl, min, to, col);     
			
			Point3D from = new Point3D(max.getX(), max.getY(), min.getZ());
			to = new Point3D(min.getX(), max.getY(), min.getZ());
			draw.drawLine(gl, from, to, col);     

			to = new Point3D(max.getX(), min.getY(), min.getZ());
			draw.drawLine(gl, from, to, col);     

        }
    }

    private void paintSectorNames() {
        for (GalaxySector sector : galaxy.getSectors()) {
            Point3D point = sector.getMin();
			font.print3D(gl, sector.getName(), point, scaleSectorFont, new Color4f(1.0f,0.5f,0.0f,1.0f));			
        }
    }

    private void paintSystemNames() {
		float size;
		for (GalaxySector sector : galaxy.getSectors()) {
			for (GalaxySystem system : sector.getSystems()) {
				if (system.hasJumps() || getFlag("show_no_jumps")) {
					Point3D point = system.getPos();
					if (point.x<viewPortMin.x | point.y<viewPortMin.y) {
						continue;
					}
					if (point.x>viewPortMax.x | point.y>viewPortMax.y) {
						continue;
					}
					StringBuffer name = new StringBuffer();
					if (getFlag("show_system_sector")) {
						name.append(system.getSector().getName());
					}
					if (getFlag("show_system_name")) {
						if (name.length() > 0) {
							name.append("/");
						}
						name.append(system.getName());
					}
					if (getFlag("show_system_faction")) {
						if (name.length() > 0) {
							name.append("/");
						}
						name.append(system.getFaction());
					}
					
					size = scaleStarFont + scaleStarFont*(float)point.z/(float)systems.sysPos.get(0).z;
					// special size for dense VS sol cluster
					if (galaxy.name.equals("vegastrike.xml")) {
						if (point.x>-26 & point.x<26 &
							point.y>-26 & point.y<26) {
							size = 0.25f*size;
						}
					}

					Color4f color = galaxy.faction.getFactionColor4f(system.getFaction());
					font.print3D(gl, name.toString(), new Point3D(point.x+0.1f, point.y-0.1f, point.z-0.1f), size, color);
				}
			}
		}
	}
    
    //------------------------------------------
    // Path Functions
    //------------------------------------------

    private void paintPath() {
        try {
            for (int i=0; i<path.size()-1; i++) {
                paintJump(path.get(i), path.get(i + 1));
            }
        } catch (Exception e) {}
    }

    private GalaxySystem getSystem(float[] p) {
        double dist = Double.MAX_VALUE;
        GalaxySystem result = null;
		Point3D p3 = new Point3D(p[0],p[1],0);	
     
	 	// identify system
        for (GalaxySector sector : galaxy.getSectors()) {
            // only look in sector(s) that was clicked
            if (p3.getX() >= sector.getMin().x && p3.getY() >= sector.getMin().y 
                    && p3.getX() <= sector.getMax().x && p3.getY() <= sector.getMax().y) {
                for (GalaxySystem system : sector.getSystems()) {
                    // filter invisible systems
                    if (system.hasJumps() || getFlag("show_no_jumps")) {
                        Point3D pos = system.getPos();
                        double tmp = pos.distance(p3.getX(), p3.getY(), pos.z);

                        if (tmp < dist) {
                            dist = tmp;
                            result = system;
                        }
                    }
                }
            }
        }
        
        return result;
    }

    public void selectSystem(float[] p) {
        GalaxySystem system = getSystem(p);
        
        if (system != null) {
            if (end != null) {
                end = null;
                path = null;
                start = system;
            } else {
                if (start != null) {
                    end = system;
                    path = pathFinder.getPath(start, end);
                    bPathSelectMode = false;
                } else {
                    start = system;
                }
            }
        }
		
    }
    
}
