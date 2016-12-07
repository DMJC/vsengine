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

import java.util.ArrayList;
import java.util.List;
import java.util.Vector;

public class GalaxyJumps {
    
    public List<String> jumpRoute;
    public List<Point3D> syspos1;
    public List<Point3D> syspos2;
    
    public boolean bJumpsReady = false;
    
    public GalaxyJumps() {
        jumpRoute = new Vector<String>();
        syspos1 = new ArrayList<Point3D>();
        syspos2 = new ArrayList<Point3D>();
    }

	public void addJumps(Galaxy galaxy) {
		//Log.i(this.getClass().getName(), "--addJumps()");
        for (GalaxySector sector : galaxy.getSectors()) {
            for (GalaxySystem system : sector.getSystems()) {
                for (GalaxySystem jump : system.getJumps()) {
					// evaluate if route already exists
					String sys1 = system.getFullName();
					String sys2 = jump.getFullName();
					if (jumpRoute.contains(sys1+"-"+sys2)) {
						continue;
					}
					if (jumpRoute.contains(sys2+"-"+sys1)) {
						continue;
					}
					jumpRoute.add(sys1+"-"+sys2);
					syspos1.add(system.getPos());
					syspos2.add(jump.getPos());					
				}
            }
        }
		
	}

    class JumpNetwork extends Thread {
        private Galaxy galaxy;
        
        JumpNetwork(Galaxy galaxy) {
            this.galaxy = galaxy;
        }
        
        @Override
        public void run() {
			
			// new method: 93052ms
			// old method: 194498ms > 2x 
			addJumps(galaxy);
			bJumpsReady = true;
			
			try {
                this.finalize();
            } catch (Throwable e) {
                e.printStackTrace();
            }
        } //run

    } // class

    public void makeJumps(Galaxy galaxy) {
        JumpNetwork mThread = new JumpNetwork(galaxy);
        mThread.start();
    }

}
