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

import java.util.Collections;
import java.util.ArrayList;
import java.util.List;

public class GalaxySystems {
    
    public List<Point3D> sysPos;
	public List<String> sysName;
	public List<String> sysFullname;
	public List<String> sortedNames;
    
    public boolean bSystemsReady = false;
    
    public GalaxySystems() {
        sysPos = new ArrayList<Point3D>();
		sysName = new ArrayList<String>();
		sysFullname = new ArrayList<String>();
		sortedNames = new ArrayList<String>();
    }

	private void sortSystems(Galaxy galaxy) {
        for (GalaxySector sector : galaxy.getSectors()) {
			//Log.i(this.getClass().getName(), "sector: " + sector.getName());
            for (GalaxySystem system : sector.getSystems()) {
				Point3D pos = system.getPos();
				String name = system.getFullName();
				int ins = 0;
				// insert position
				for (int i=0; i<sysPos.size(); i++) {
					Point3D ipos = sysPos.get(i);
					if (ipos.z <= pos.z) {
						ins = i;
						break;
					}
					if (i==sysPos.size()-1) {
						ins = sysPos.size();	
					}
				}
				//Log.i(this.getClass().getName(), "ins: " + ins);
				sysPos.add(ins, pos);
				sysName.add(ins, name.split("/")[1]);
				sysFullname.add(ins, name);
			}
		}
	}

	private void sortNames() {
		 // sort entries alphabetically
		 for (int i=0; i<sysName.size(); i++) {
			 sortedNames.add(sysName.get(i));
		 }
		 Collections.sort(sortedNames);		
	}
	
    class Systems extends Thread {
        private Galaxy galaxy;
        
        Systems(Galaxy galaxy) {
            this.galaxy = galaxy;
        }
        
        @Override
        public void run() {
			
			sortSystems(galaxy);
			sortNames();
			bSystemsReady = true;
			
			try {
                this.finalize();
            } catch (Throwable e) {
                e.printStackTrace();
            }
        } //run

    } // class

    public void makeSystems(Galaxy galaxy) {
        Systems mThread = new Systems(galaxy);
        mThread.start();
    }

}
