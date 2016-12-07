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
import java.util.Vector;

import android.util.Log;

public class GalaxySector {
    
    private String name;
    private Map<String, GalaxySystem> systems;
    
    private Point3D min;
    private Point3D max;
    
    public GalaxySector(String name) {
        this.name = name;
        
        min = null;
        max = null;
        
        systems = new Hashtable<String, GalaxySystem>();
    }
    
    public String getName() {
        return name;
    }
    
    public List<GalaxySystem> getSystems() {
        return new Vector<GalaxySystem>(systems.values());
    }
    
    public GalaxySystem getSystem(String name) {
        return systems.get(name);
    }
    
    public void addSystem(GalaxySystem system) {
        try {
            systems.put(system.getName(), system);
            system.setSector(this);
        } catch (OutOfMemoryError e) {
            Log.i(this.getClass().getName(), "systems count = " + systems.size());
            Log.e(this.getClass().getName(), "OutOfMemoryError: Universe loading incomplete");
            return;
        }
        
        Point3D pos = system.getPos();
        if (min == null) {
            min = new Point3D(pos);
            max = new Point3D(pos);
            return;
        }
        
        if (pos.x < min.x) {
            min.x = pos.x;
        }
        if (pos.y < min.y) {
            min.y = pos.y;
        }
        if (pos.z < min.z) {
            min.z = pos.z;
        }
        if (pos.x > max.x) {
            max.x = pos.x;
        }
        if (pos.y > max.y) {
            max.y = pos.y;
        }
        if (pos.z > max.z) {
            max.z = pos.z;
        }
    }
    
    public Point3D getMin() {
        return min;
    }
    
    public Point3D getMax() {
        return max;
    }

}
