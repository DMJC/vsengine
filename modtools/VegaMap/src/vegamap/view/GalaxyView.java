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

package vegamap.view;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.awt.geom.Point2D;
import java.awt.Dimension;
import java.io.File;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;
import java.util.Vector;
import javax.swing.JFrame;
import javax.swing.JPanel;
import vegamap.Galaxy;
import vegamap.GalaxySector;
import vegamap.GalaxySystem;
import vegamap.PathFinder;
import vegamap.Point3D;
import java.lang.Double;

public class GalaxyView extends JPanel 
        implements MouseListener, MouseWheelListener, KeyListener {
    
    public static final String VERSION = "0.23 | 2011-03-23";
    
    public static final String[] PARAMS = { "-f", "-h", "--help", "--version", "/?" };
    public static final boolean[] PARAM_ARGS = { true, false, false, false, false };
    
    private double STAR_RADIUS = 5;
    private static final int SECTOR_MARGIN = 5;
    
    private Galaxy galaxy;
    
    private Point2D center;
    private double scale;
    private double center_x_min = 0;
    private double center_x_max = 0;
    private double center_y_min = 0;
    private double center_y_max = 0;
    
    private Map<String, Boolean> flags;
    
    private GalaxySystem start;
    private GalaxySystem end;
    private List<GalaxySystem> path;
    
    private PathFinder pathFinder;
    
    public GalaxyView(Galaxy galaxy) {
        this.galaxy = galaxy;
        List<GalaxySector> sectors = this.galaxy.getSectors();
        
        // calculate map center
        for (GalaxySector sector : sectors) {
            for (GalaxySystem system : sector.getSystems()) {
                Point3D pos = system.getPos();
                center_x_min = Math.min(pos.x, center_x_min);
                center_x_max = Math.max(pos.x, center_x_max);
                center_y_min = Math.min(pos.y, center_y_min);
                center_y_max = Math.max(pos.y, center_y_max);
            }
        }
        center = new Point2D.Double(center_x_min+(center_x_max-center_x_min)/2, center_y_min+(center_y_max-center_y_min)/2);
        //center = new Point2D.Double(481, -628); // VS approximate center
        scale = 0.45; // default scale = 10.0;
        
        flags = new Hashtable<String, Boolean>();
        setFlag("show_no_jumps", false);
        setFlag("show_system_name", false);
        setFlag("show_system_faction", false);
        setFlag("show_system_sector", false);
        setFlag("show_sector_boxes", false);
        setFlag("reverse_y_axis", true);
        setFlag("show_jump_lines", true);
        setFlag("show_help", false);
        setFlag("show_compass", true);
        setFlag("show_homeworld", false);

        start = null;
        end = null;
        path = null;
        
        pathFinder = new PathFinder(galaxy);
        
        addMouseListener(this);
        addMouseWheelListener(this);
        addKeyListener(this);
        
        setFocusable(true);
        
        setBackground(Color.BLACK);
    }
 
    // paint something on the screen
    protected void paintComponent(Graphics graphics) {
        super.paintComponent(graphics);
        
        Graphics g = graphics.create();
        
        paintJumps(g);
        if (getFlag("show_sector_boxes")) {
            paintSectorBoxes(g);
        }
        paintSystems(g);
        if (path != null) {
            paintPath(g);
        }
        if (getFlag("show_help")) { paintHelp(g); }
        if (getFlag("show_compass")) { paintCompass(g); }
        if (getFlag("show_homeworld")) { paintHomeworlds(g); }
    }

    private void paintHelp(Graphics graphics) {
        Graphics g = graphics.create();
        g.setColor(Color.WHITE);
        // left column
        g.drawString("ESC - hide legend", 10, 20);
        g.drawString("  Q - quit", 10, 40);
        g.drawString("  N - system names", 10, 60);
        g.drawString("  S - sector names", 10, 80);
        g.drawString("  F - faction names", 10, 100);
        g.drawString("  J - jumpless systems", 10, 120);
        g.drawString("  L - jump lines", 10, 140);
        g.drawString("  B - sector boxes", 10, 160);
        g.drawString("  R - reverse y-axis", 10, 180);
        g.drawString("  Z - zoom in", 10, 200);
        g.drawString("  X - zoom out", 10, 220);
        g.drawString("  C - toggle compass rose", 10, 240);
        g.drawString("  H - toggle home worlds", 10, 260);
        g.drawString("RMB - recenter", 10, 280);
        g.drawString("+/- - increase/decrease system bubble", 10, 300);
        //right column
        g.drawString("view scale = " + Double.toString(scale), 300, 20);
        g.drawString("star radius = " + Double.toString(STAR_RADIUS), 300, 40);
        g.drawString("galactic center = (" + Double.toString(center_x_min+(center_x_max-center_x_min)/2) + ", " + Double.toString(center_y_min+(center_y_max-center_y_min)/2) + ")", 300, 60);
        //center_x_min
    }
    
    private void paintHomeworlds(Graphics graphics) {
        // Vega Strike species and faction home systems
        String[] HOMESYSTEMS = { "Sol", "Aeneilylk", "Gohdahru", "Regallis", "Bifrost", "Talos", "Kishar",
            "Mu_Ara", "Chang_cu", "Agea", "Palan", "Ea", "Ross248", "Kirov", "Spielberg", "Trotsky",
            "Cardell", "Hehet", "Bzzkabtl", "Izzahbtl", "Ptkabizz", "Zeenyqqh", "Zeen" };
        for (GalaxySector sector : galaxy.getSectors()) {
            for (GalaxySystem system : sector.getSystems()) {
                for (int i = 0; i < HOMESYSTEMS.length; i++) {
                    if (system.getName().equals(HOMESYSTEMS[i])) {
                        Point3D tmp = system.getPos();
                        Point2D loc = new Point2D.Double(tmp.getX(), tmp.getY());
                        Point p = getViewPoint(loc);
                        graphics.drawOval((int)(p.x - 3*STAR_RADIUS*scale/2), (int)(p.y - 3*STAR_RADIUS*scale/2), 
                                (int)(3*STAR_RADIUS * scale), (int)(3*STAR_RADIUS * scale));
                        graphics.drawOval((int)(p.x - 2*STAR_RADIUS*scale/2), (int)(p.y - 2*STAR_RADIUS*scale/2), 
                                (int)(2*STAR_RADIUS * scale), (int)(2*STAR_RADIUS * scale));
                        graphics.drawOval((int)(p.x - 1.5*STAR_RADIUS*scale/2), (int)(p.y - 1.5*STAR_RADIUS*scale/2), 
                                (int)(1.5*STAR_RADIUS * scale), (int)(1.5*STAR_RADIUS * scale));
                    }
                }
            }
        }
    }

    private void paintCompass(Graphics graphics) {
        int SIZE = 100; // cmpass outline dimensions
        int MARGIN = 30;
        int ARROW = 2;
        int screenX = graphics.getClipBounds().width; // window size
        int screenY = graphics.getClipBounds().height;
        graphics.setColor(new Color(255,255,255));
        //System.out.println(Integer.toString(graphics.getClipBounds().width));
        // draw lines
        graphics.drawLine(screenX - MARGIN - SIZE/2, MARGIN, screenX - MARGIN - SIZE/2, MARGIN + SIZE);
        graphics.drawLine(screenX - MARGIN, MARGIN + SIZE/2, screenX - MARGIN - SIZE, MARGIN + SIZE/2);
        // draw arrows
        graphics.drawLine(screenX - MARGIN - SIZE/2, MARGIN, screenX - MARGIN - SIZE/2 - ARROW, MARGIN + SIZE/2); //top
        graphics.drawLine(screenX - MARGIN - SIZE/2, MARGIN, screenX - MARGIN - SIZE/2 + ARROW, MARGIN + SIZE/2);
        graphics.drawLine(screenX - MARGIN - SIZE/2, MARGIN + SIZE, screenX - MARGIN - SIZE/2 - ARROW, MARGIN + SIZE/2); //bottom
        graphics.drawLine(screenX - MARGIN - SIZE/2, MARGIN + SIZE, screenX - MARGIN - SIZE/2 + ARROW, MARGIN + SIZE/2);
        graphics.drawLine(screenX - MARGIN, MARGIN + SIZE/2, screenX - MARGIN - SIZE/2, MARGIN + SIZE/2 + ARROW); //right
        graphics.drawLine(screenX - MARGIN, MARGIN + SIZE/2, screenX - MARGIN - SIZE/2, MARGIN + SIZE/2 - ARROW);
        graphics.drawLine(screenX - MARGIN - SIZE, MARGIN + SIZE/2, screenX - MARGIN - SIZE/2, MARGIN + SIZE/2 + ARROW); //left
        graphics.drawLine(screenX - MARGIN - SIZE, MARGIN + SIZE/2, screenX - MARGIN - SIZE/2, MARGIN + SIZE/2 - ARROW);
        // draw text
        if (getFlag("reverse_y_axis")) {
            graphics.drawString("rimward", screenX - MARGIN - SIZE/2, MARGIN - 5);
            graphics.drawString("coreward", screenX - MARGIN - SIZE/2 - 45, MARGIN + SIZE + 15);
        } else {
            graphics.drawString("coreward", screenX - MARGIN - SIZE/2, MARGIN - 5);
            graphics.drawString("rimward", screenX - MARGIN - SIZE/2 - 50, MARGIN + SIZE + 15);
        }
    graphics.drawString("spinward", screenX - MARGIN - SIZE - 5, MARGIN + SIZE/2 - 10);
    graphics.drawString("anti-spinward", screenX - MARGIN - SIZE/2 + 5, MARGIN + SIZE/2 + 15);
    }

    private void paintJumps(Graphics graphics) {
        Graphics g = graphics.create();
        g.setColor(Color.DARK_GRAY);
        
        for (GalaxySector sector : galaxy.getSectors()) {
            for (GalaxySystem system : sector.getSystems()) {
                if (system.hasJumps() && getFlag("show_jump_lines")) {
                    for (GalaxySystem other : system.getJumps()) {
                        paintJump(g, system, other);
                    }
                }
            }
        }
    }
    
    private void paintJump(Graphics graphics, GalaxySystem start, GalaxySystem end) {
        Point3D tmp1 = start.getPos();
        Point2D loc1 = new Point2D.Double(tmp1.getX(), tmp1.getY());
        Point p1 = getViewPoint(loc1);
        
        Point3D tmp2 = end.getPos();
        Point2D loc2 = new Point2D.Double(tmp2.getX(), tmp2.getY());
        Point p2 = getViewPoint(loc2);
        
        graphics.drawLine(p1.x, p1.y, p2.x, p2.y);
    }
    
    private void paintSectorBoxes(Graphics graphics) {
        Graphics g = graphics.create();
        g.setColor(Color.ORANGE);
        
        for (GalaxySector sector : galaxy.getSectors()) {
            Point3D min = sector.getMin();
            Point3D max = sector.getMax();
            
            Point2D tmpMin = new Point2D.Double(min.x, min.y);
            Point2D tmpMax = new Point2D.Double(max.x, max.y);
            
            Point p1 = getViewPoint(tmpMin);
            Point p2 = getViewPoint(tmpMax);
            
            int x = p1.x;
            int y = Math.min(p1.y, p2.y);
            int width = Math.abs(p1.x - p2.x);
            int height = Math.abs(p1.y - p2.y);
            
           g.drawRect(x - (int)(SECTOR_MARGIN * scale), y - (int)(SECTOR_MARGIN * scale), width + (int)(SECTOR_MARGIN * scale), height + (int)(SECTOR_MARGIN * scale));
           g.drawString(sector.getName(), x - (int)(SECTOR_MARGIN * scale) + 5, y - (int)(SECTOR_MARGIN * scale) + 15);
        }
    }
    
    private void paintSystems(Graphics graphics) {
        Graphics g = graphics.create();
        
        g.setColor(Color.WHITE);
        
        for (GalaxySector sector : galaxy.getSectors()) {
            for (GalaxySystem system : sector.getSystems()) {

                g.setColor(system.getFactionColor(system.getFaction()));
                if (system.hasJumps() || getFlag("show_no_jumps")) {
                    paintSystem(g, system);
                }
            }
        }
        
        // always show selected systems on top
        g.setColor(Color.RED);
        
        if (start != null) {
            paintSystem(g, start);
        }
        if (end != null) {
            paintSystem(g, end);
        }
    }
    
    private void paintSystem(Graphics graphics, GalaxySystem system) {
        Point3D tmp = system.getPos();
        Point2D loc = new Point2D.Double(tmp.getX(), tmp.getY());
        Point p = getViewPoint(loc);

        graphics.fillOval((int)(p.x - STAR_RADIUS*scale/2), (int)(p.y - STAR_RADIUS*scale/2), 
                (int)(STAR_RADIUS * scale), (int)(STAR_RADIUS * scale));

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

        graphics.drawString(name.toString(), (int)(p.x + STAR_RADIUS*scale/2), (int)(p.y - STAR_RADIUS*scale/2));
    }
    
    private void paintPath(Graphics graphics) {
        Graphics g = graphics.create();
        
        g.setColor(Color.RED);
        
        for (int i = 0; i < path.size() - 1; i++) {
            paintJump(g, path.get(i), path.get(i + 1));
        }
        
        for (int i = 0; i < path.size(); i++) {
            paintSystem(g, path.get(i));
        }
    }
    
    public void recenter(Point2D center) {
        this.center = center;
        repaint();
    }
    
    public void rescale(double scale) {
        this.scale = scale;
        
        repaint();
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
    
    public void mouseClicked(MouseEvent e) {
        Point p = e.getPoint();
        int button = e.getButton();
        
        if (button == MouseEvent.BUTTON1) {
            Point2D mapP = getMapPoint(p);
            
            selectSystem(mapP);
        }
        if (button == MouseEvent.BUTTON3) {
            Point2D mapP = getMapPoint(p);
            recenter(mapP);
        }
    }
    
    public void mouseWheelMoved(MouseWheelEvent e) {
        int clicks = e.getWheelRotation();
        
        if (clicks != 0) {
            rescale(scale * (1.0 - 0.1 * clicks));
        }
    }

    public void keyTyped(KeyEvent e) {
        char c = e.getKeyChar();
        switch (c) {
            case 'j':
                toggleFlag("show_no_jumps");
                repaint();
                break;
            case 'l':
                toggleFlag("show_jump_lines");
                repaint();
                break;
            case 'n':
                toggleFlag("show_system_name");
                repaint();
                break;
            case 'f':
                toggleFlag("show_system_faction");
                repaint();
                break;
            case 's':
                toggleFlag("show_system_sector");
                repaint();
                break;
            case 'b':
                toggleFlag("show_sector_boxes");
                repaint();
                break;
            case 'r':
                toggleFlag("reverse_y_axis");
                repaint();
                break;
            case 'c':
                toggleFlag("show_compass");
                repaint();
                break;
            case 'z':
                rescale(scale * (1.0 + 0.1));
                repaint();
                break;
            case 'Z':
                rescale(scale * (1.0 - 0.1));
                repaint();
                break;
            case 'x':
                rescale(scale * (1.0 - 0.1));
                repaint();
                break;
            case 'q':
                System.exit(0);
                break;
            case '+':
                STAR_RADIUS += 1/scale;
                repaint();
                break;
            case '-':
                STAR_RADIUS = Math.max(0, STAR_RADIUS - 1/scale);
                repaint();
                break;
            case '':
                toggleFlag("show_help");
                repaint();
                break;
            case 'h':
                toggleFlag("show_homeworld");
                repaint();
                break;
        }
    }

    private Point2D getMapPoint(Point p) {
        Point vc = getViewCenter();
        Point tp;
        if (getFlag("reverse_y_axis")) {
            tp = new Point(p.x - vc.x, p.y - vc.y);
        } else {
            tp = new Point(p.x - vc.x, - (p.y - vc.y));
        }
        
        Point2D result = new Point2D.Double(
                center.getX() + tp.x / scale, 
                center.getY() + tp.y / scale);
        
        return result;
    }
    
    private Point getViewPoint(Point2D p) {
        Point shift = getViewCenter();
        
        int x = (int)Math.round((p.getX() - center.getX()) * scale) + shift.x;
        int y;
        if (getFlag("reverse_y_axis")) {
            y = (int)Math.round((p.getY() - center.getY()) * scale) + shift.y;
        } else {
            y = (int)Math.round(- (p.getY() - center.getY()) * scale) + shift.y;
        }
        
        return new Point(x, y);
    }
    
    private Point getViewCenter() {
        return new Point(getWidth() / 2, getHeight() / 2);
    }
    
    private GalaxySystem getSystem(Point2D p) {
        double dist = Double.MAX_VALUE;
        GalaxySystem result = null;
        
        for (GalaxySector sector : galaxy.getSectors()) {
            // only look in sector(s) that was clicked
            if (p.getX() >= sector.getMin().x && p.getY() >= sector.getMin().y 
                    && p.getX() <= sector.getMax().x && p.getY() <= sector.getMax().y) {
                for (GalaxySystem system : sector.getSystems()) {
                    // filter invisible systems
                    if (system.hasJumps() || getFlag("show_no_jumps")) {
                        Point3D pos = system.getPos();
                        double tmp = pos.distance(p.getX(), p.getY(), pos.z);

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
    
    private void selectSystem(Point2D p) {
        GalaxySystem system = getSystem(p);
        
        if (system != null) {
            if (end != null) {
                end = null;
                start = system;
                path = null;
            } else {
                if (start != null) {
                    end = system;
                    path = pathFinder.getPath(start, end);
                    printPath();
                } else {
                    start = system;
                }
            }
            
            repaint();
        }
    }
    
    private void printPath() {
        if (path != null) {
            System.out.println("Path found (" + (path.size() - 1) + " jumps):");
            
            for (int i = 0; i < path.size(); i++) {
                System.out.println(path.get(i).getFullName());
            }
        } else {
            System.out.println("No path from " + start.getFullName() + 
                    " to " + end.getFullName() + " found.");
        }
    }
    
    public static Map<String, String> parseCommandLine(String[] args) {
        Map<String, String> result = new Hashtable<String, String>();
        
        for (int i = 0; i < args.length; i++) {
            int param = -1;
            for (int j = 0; j < PARAMS.length; j++) {
                if (args[i].equals(PARAMS[j])) {
                    param = j;
                    break;
                }
            }
            
            // check if a matching parameter was found
            if (param < 0) {
                System.out.print("vegamap: Unknown parameter");
                System.out.println(": " + args[i]);
                return null;
            }
            
            // check if parameter needs an argument
            if (param >= 0 && PARAM_ARGS[param]) {
                if (i == args.length - 1) {
                    System.out.print("vegamap: Missing argument for parameter");
                    System.out.println(": " + args[i]);
                    return null;
                }
                
                i++;
                result.put(PARAMS[param], args[i]);
            } else {
                result.put(PARAMS[param], "");
            }
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        Map<String, String> params = parseCommandLine(args);
        String fileName = "milky_way.xml";

        // print  command line help
        if (args.length>0) {
            if (args[0].equals("--help") || args[0].equals("-h") || args[0].equals("/?")) {
                System.out.println("Usage: vsmap");
                System.out.println("       java -jar vegamap.jar");
                System.out.println("       java -jar vegamap.jar -f /pathto/milky_way.xml");
                System.out.println("       java -jar vegamap.jar --help");
                System.out.println("Use ESC key to show in-app control keys.");
                System.exit(1);
            }
            if (args[0].equals("--version")) {
                System.out.println("Vega Map version " + VERSION);
                System.exit(1);
            }
        }

        // if null is returned, then assume default file name
        if (params == null) {
            fileName = "milky_way.xml";
        }

        String paramName = params.get("-f");
        if (paramName != null) {
            fileName = paramName;
            //System.out.println("vegamap: missing file argument (-f <path to milky_way.xml>)");
            //System.exit(1);
        }
        
        Galaxy gal = null;
        try {
            gal = new Galaxy(new File(fileName));
        } catch (Exception e) {
            e.printStackTrace();
            return;
        }
        
        GalaxyView view = new GalaxyView(gal);
        
        JFrame f = new JFrame("GalaxyView");
        f.setContentPane(view);
        f.setSize(800, 600);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
    
    public void mouseReleased(MouseEvent e) {
    }

    public void mousePressed(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }

    public void mouseEntered(MouseEvent e) {
    }

    public void keyReleased(KeyEvent e) {
    }

    public void keyPressed(KeyEvent e) {
    }

}