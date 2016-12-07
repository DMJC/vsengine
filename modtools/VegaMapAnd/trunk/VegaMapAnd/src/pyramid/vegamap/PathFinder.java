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
import java.util.PriorityQueue;
import java.util.Vector;

public class PathFinder {
    
    //private Galaxy galaxy;
    
    public PathFinder(Galaxy galaxy) {
        //this.galaxy = galaxy;
    }
    
    public List<GalaxySystem> getPath(GalaxySystem start, GalaxySystem end) {
        VerticeQueue q = new VerticeQueue();
        q.add(new Vertice(start, 0));
        
        Map<GalaxySystem, Vertice> found = new Hashtable<GalaxySystem, Vertice>(); 
        
        while (!q.isEmpty()) {
            // remove nearest vertice from queue
            Vertice c = q.remove();
            // check if vertice was reached
            if (c.dist == Integer.MAX_VALUE) {
                // all remaining vertices unreachable
                break;
            }
            found.put(c.system, c);
            
            if (c.system == end) {
                break;
            }
            
            // check for neighbours
            for (GalaxySystem s : c.system.getJumps()) {
                // get base distance to neighbour
                int dist = 1;
                
                int newDist = c.dist + dist;
                Vertice other = q.get(s);

                if (other != null) {
                    if (newDist < other.dist) {
                        other = q.remove(s);

                        other.dist = newDist;
                        other.prev = c.system; 

                        q.add(other); 
                    }
                } else {
                    if (!found.containsKey(s)) {
                        other = new Vertice(s, newDist);
                        other.prev = c.system;

                        q.add(other); 
                    }
                }
            }
        }
        
        if (found.get(end) == null) {
            return null;
        }
        
        List<GalaxySystem> result = new Vector<GalaxySystem>();
        GalaxySystem current = end;
        while (current != start) {
            Vertice v = found.get(current);
            result.add(0, v.system);
            current = v.prev;
        }
        result.add(0, start);
        
        return result;
    }
    
    private class VerticeQueue {
        
        private Map<GalaxySystem, Vertice> map;
        private PriorityQueue<Vertice> queue;
        
        public VerticeQueue() {
            map = new Hashtable<GalaxySystem, Vertice>();
            queue = new PriorityQueue<Vertice>();
        }
        
        public void add(Vertice v) {
            map.put(v.system, v);
            queue.add(v);
        }
        
        public boolean contains(GalaxySystem s) {
            return map.get(s) != null;
        }
        
        public Vertice get(GalaxySystem s) {
            return map.get(s);
        }
        
        public Vertice remove(GalaxySystem s) {
            Vertice v = map.get(s);
            map.remove(v);
            queue.remove(v);
            return v;
        }
        
        public Vertice remove() {
            Vertice v = queue.remove();
            map.remove(v);
            return v;
        }
        
        public boolean isEmpty() {
            return queue.isEmpty();
        }
        
    }
    
    private class Vertice implements Comparable<Vertice> {
        
        public GalaxySystem system;
        public int dist;
        public GalaxySystem prev;
        
        public Vertice(GalaxySystem system, int dist) {
            this.system = system;
            this.dist = dist;
            this.prev = null;
        }
        
        public int compareTo(Vertice v) {
            if (dist < v.dist) {
                return -1;
            }
            if (dist > v.dist) {
                return 1;
            }
            return 0;
        }
        
    }
    
}
