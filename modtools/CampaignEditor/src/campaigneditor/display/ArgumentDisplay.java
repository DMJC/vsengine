/*
 * ArgumentDisplay.java
 *
 * Created on September 22, 2005, 11:00 AM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor.display;

import campaigneditor.Campaign;
import campaigneditor.arguments.Argument;
import javax.swing.JPanel;

/**
 *
 * @author daniel
 */
public abstract class ArgumentDisplay extends JPanel
{
    public abstract void updateDisplay();
    
    public abstract void updateArgument();
    
    public abstract void setArgument(Argument newarg);
    
    public abstract Argument getArgument();
    
    /* Set the campaign, to make available additional information. */
    public void setCampaign(Campaign campaign)
    {
        return;
    }
}
