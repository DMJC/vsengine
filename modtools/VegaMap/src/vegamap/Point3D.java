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

public class Point3D implements Cloneable {
    
    public double x;
    public double y;
    public double z;
    
    public Point3D() {
        this.x = 0.0;
        this.y = 0.0;
        this.z = 0.0;
    }
    
    public Point3D(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    
    public Point3D(Point3D p) {
        this.x = p.getX();
        this.y = p.getY();
        this.z = p.getZ();
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getZ() {
        return z;
    }

    public void setZ(double z) {
        this.z = z;
    }
    
    public void setLocation(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    
    public void setLocation(Point3D p) {
        setLocation(p.getX(), p.getY(), p.getZ());
    }
    
    public double distance(double px, double py, double pz) {
        return Math.sqrt(sqr(x - px) + sqr(y - py) + sqr(z - pz));
    }
    
    public Object clone() {
        return new Point3D(this);
    }
    
    private double sqr(double a) {
        return a * a;
    }
    
}
