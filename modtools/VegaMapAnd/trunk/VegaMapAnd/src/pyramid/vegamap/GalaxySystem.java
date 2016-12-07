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

import java.util.List;
import java.util.Vector;

public class GalaxySystem {
    
    private String name;
    private Point3D pos;
    private String faction;
    private GalaxySector sector;
    private List<String> jumpStrings;
    private List<GalaxySystem> jumps;
    
    public GalaxySystem(String name, Point3D pos, String faction, GalaxySector sector) {
        this.name = name;
        this.pos = pos;
        this.faction = faction;
        this.sector = sector;
        
        jumpStrings = new Vector<String>();
        jumps = new Vector<GalaxySystem>();
    }
    
    public String getName() {
        return name;
    }
    
    public String getFullName() {
        return sector.getName() + "/" + getName();
    }
    
    public Point3D getPos() {
        return pos;
    }
    
    public String getFaction() {
        return faction;
    }
    
    public GalaxySector getSector() {
        return sector;
    }
    
    public void setSector(GalaxySector sector) {
        this.sector = sector;
    }
    
    public List<String> getJumpStrings() {
        return jumpStrings;
    }
    
    public void addJumpString(String jump) {
        jumpStrings.add(jump);
    }
    
    public void clearJumpStrings() {
        jumpStrings.clear();
    }
    
    public List<GalaxySystem> getJumps() {
        return jumps;
    }
    
    public boolean hasJumps() {
        return jumps.size() > 0;
    }
    
    public void addJump(GalaxySystem system) {
        jumps.add(system);
    }
    
}
