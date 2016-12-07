/*
 * Main.java
 *
 * Created on 1 June 2005, 21:43
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor;

import campaigneditor.display.MainFrameDisplay;
import javax.swing.UIManager;

/**
 *
 * @author Daniel Aleksandrow aka dandandaman
 * @author pyramid
 * @version 0.02 | 2011-04-01
 */
public class Main {
    
    /** Creates a new instance of Main */
    private static void displayGUI() {
        //Uncomment to switch look/feel to metal, rather than platform default
        //JFrame.setDefaultLookAndFeelDecorated(true);
        
        try
        {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        }
        catch (Exception e)
        {
          System.out.println("Unable to load native look and feel");
        }
        new MainFrameDisplay().setVisible(true);
    }
    
    public static void main(String[] args) {
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                displayGUI();
            }
        });
    }
}
