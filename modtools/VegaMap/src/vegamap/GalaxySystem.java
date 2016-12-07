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

import java.util.List;
import java.util.Vector;
import java.awt.Color;

public class GalaxySystem {
    
    private String name;
    private Point3D pos;
    private String faction;
    private GalaxySector sector;
    private List<String> jumpStrings;
    private List<GalaxySystem> jumps;
    
    public GalaxySystem(String name, Point3D pos, String faction) {
        this.name = name;
        this.pos = pos;
        this.faction = faction;
        
        sector = null;
        
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

    public Color getFactionColor(String faction) {
        Color factionColor = new Color(77, 77, 77); //unknown
        // colors for VS Upon The Coldes Sea
        if (faction.equals("aera")) { factionColor = new Color(102, 255, 102); }
        if (faction.equals("aeran_merchant_marine")) { factionColor = new Color(100, 185, 19); }
        if (faction.equals("bzbr")) { factionColor = new Color(82, 246, 101); }
        if (faction.equals("rlaan")) { factionColor = new Color(102, 0, 153); }
        if (faction.equals("rlaan_enforcers")) { factionColor = new Color(5, 0, 255); }
        if (faction.equals("rlaan_briin")) { factionColor = new Color(150, 35, 116); }
        if (faction.equals("rlaan_citizen")) { factionColor = new Color(102, 0, 153); }
        if (faction.equals("lmpl")) { factionColor = new Color(255, 20, 147); }
        if (faction.equals("nuhln")) { factionColor = new Color(139, 0, 80); }
        if (faction.equals("saahasaqyaay")) { factionColor = new Color(217, 38, 89); }
        if (faction.equals("confed")) { factionColor = new Color(0, 0, 255); }
        if (faction.equals("andolian")) { factionColor = new Color(0, 30, 184); }
        if (faction.equals("klkk")) { factionColor = new Color(51, 77, 204); }
        if (faction.equals("purth")) { factionColor = new Color(26, 51, 179); }
        if (faction.equals("highborn")) { factionColor = new Color(0, 51, 204); }
        if (faction.equals("homeland-security")) { factionColor = new Color(0, 77, 153); }
        if (faction.equals("intelsec")) { factionColor = new Color(0, 102, 255); }
        if (faction.equals("confed_navy")) { factionColor = new Color(0, 153, 255); }
        if (faction.equals("hunter")) { factionColor = new Color(0, 79, 113); }
        if (faction.equals("LIHW")) { factionColor = new Color(38, 64, 115); }
        if (faction.equals("mechanist")) { factionColor = new Color(77, 77, 128); }
        if (faction.equals("merchant_guild")) { factionColor = new Color(51, 51, 140); }
        if (faction.equals("purist")) { factionColor = new Color(255, 153, 0); }
        if (faction.equals("dgn")) { factionColor = new Color(102, 0, 0); }
        if (faction.equals("unadorned")) { factionColor = new Color(118, 85, 95); }
        if (faction.equals("mishtali")) { factionColor = new Color(95, 35, 40); }
        if (faction.equals("forsaken")) { factionColor = new Color(92, 51, 23); }
        if (faction.equals("uln")) { factionColor = new Color(77, 128, 0); }
        if (faction.equals("luddites")) { factionColor = new Color(255, 127, 0); }
        if (faction.equals("pirates")) { factionColor = new Color(255, 0, 0); }
        if (faction.equals("ISO")) { factionColor = new Color(255, 26, 255); }
        if (faction.equals("lightbearer")) { factionColor = new Color(133, 140, 128); }
        if (faction.equals("susim")) { factionColor = new Color(124, 213, 89); }
        if (faction.equals("sucets")) { factionColor = new Color(124, 213, 89); }
        if (faction.equals("ancientsa")) { factionColor = new Color(255, 204, 0); }
        if (faction.equals("ancientsb")) { factionColor = new Color(255, 204, 51); }
        if (faction.equals("TWHON")) { factionColor = new Color(255, 255, 0); }
        if (faction.equals("hoffmans-blobs")) { factionColor = new Color(188, 119, 174); }
        if (faction.equals("shmrn")) { factionColor = new Color(214, 64, 23); }
        if (faction.equals("shaper")) { factionColor = new Color(153, 0, 0); }
        if (faction.equals("spaceborn")) { factionColor = new Color(153, 153, 255); }
        if (faction.equals("privateer")) { factionColor = new Color(255, 255, 255); }
        if (faction.equals("merchant_guild_citizen")) { factionColor = new Color(51, 51, 140); }
        if (faction.equals("andolian_citizen")) { factionColor = new Color(0, 30, 184); }
        if (faction.equals("highborn_citizen")) { factionColor = new Color(0, 51, 255); }
        if (faction.equals("shaper_citizen")) { factionColor = new Color(51, 0, 0); }
        if (faction.equals("unadorned_citizen")) { factionColor = new Color(42, 9, 18); }
        if (faction.equals("purist_citizen")) { factionColor = new Color(255, 51, 0); }
        if (faction.equals("forsaken_citizen")) { factionColor = new Color(92, 51, 23); }
        if (faction.equals("LIHW_citizen")) { factionColor = new Color(38, 64, 115); }
        if (faction.equals("uln_citizen")) { factionColor = new Color(77, 128, 0); }
        if (faction.equals("dgn_citizen")) { factionColor = new Color(102, 0, 0); }
        if (faction.equals("klkk_citizen")) { factionColor = new Color(51, 77, 204); }
        if (faction.equals("mechanist_citizen")) { factionColor = new Color(26, 26, 51); }
        if (faction.equals("shmrn_citizen")) { factionColor = new Color(214, 64, 23); }
        // additional colors for Privateer Parallel Universe
        if (faction.equals("kilrathi")) { factionColor = new Color(255, 0, 0); }
        if (faction.equals("nephilim")) { factionColor = new Color(0, 255, 0); }
        if (faction.equals("merchant")) { factionColor = new Color(128, 0, 255); }
        if (faction.equals("retro")) { factionColor = new Color(255, 77, 0); }
        if (faction.equals("militia")) { factionColor = new Color(0, 128, 255); }
        if (faction.equals("landreich")) { factionColor = new Color(0, 0, 128); }
        if (faction.equals("border_worlds")) { factionColor = new Color(0, 255, 255); }
        if (faction.equals("firekkan")) { factionColor = new Color(0, 192, 255); }
        if (faction.equals("steltek")) { factionColor = new Color(64, 255, 64); }
        if (faction.equals("riordian")) { factionColor = new Color(153, 153, 153); }
        if (faction.equals("seelig")) { factionColor = new Color(102, 51, 179); }
        if (faction.equals("kroiz")) { factionColor = new Color(128, 128, 128); } // changed from (153, 153, 153)
        if (faction.equals("miggs")) { factionColor = new Color(102, 79, 128); } // changed from (153, 153, 153)
        if (faction.equals("toth")) { factionColor = new Color(128, 0, 255); }
        if (faction.equals("garrovick")) { factionColor = new Color(128, 153, 153); } // changed from (153, 153, 153)
        if (faction.equals("reismann")) { factionColor = new Color(0, 28, 153); } // changed from (0, 0, 255)
        if (faction.equals("AWACS")) { factionColor = new Color(204, 0, 0); } // changed from (255, 0, 0)
        if (faction.equals("civilian")) { factionColor = new Color(128, 192, 255); } // changed from (128, 0, 255)
        // additional colors for Vega Trek / Star Trek Universe
        if (faction.equals("neutral")) { factionColor = new Color(204, 204, 204); }
        if (faction.equals("federation")) { factionColor = new Color(0, 0, 255); }
        if (faction.equals("romulan")) { factionColor = new Color(255, 0, 0); }
        if (faction.equals("orion_syndicate")) { factionColor = new Color(0, 255, 0); }
        if (faction.equals("borg")) { factionColor = new Color(255, 77, 0); }
        if (faction.equals("maquis")) { factionColor = new Color(153, 153, 153); }
        if (faction.equals("starfleet")) { factionColor = new Color(0, 128, 255); }
        if (faction.equals("klingon")) { factionColor = new Color(26, 128, 204); }
        if (faction.equals("cardassian")) { factionColor = new Color(0, 255, 255); }
        if (faction.equals("ferengi")) { factionColor = new Color(0, 204, 255); }
        if (faction.equals("dominion")) { factionColor = new Color(255, 77, 77); }
        if (faction.equals("tholian")) { factionColor = new Color(77, 77, 255); }
        if (faction.equals("breen")) { factionColor = new Color(51, 204, 128); }
        // empty template
        //if (faction.equals("")) { factionColor = new Color(0, 0, 0); }
        return factionColor;
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
