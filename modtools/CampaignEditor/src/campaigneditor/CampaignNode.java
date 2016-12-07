/*
 * CampaignNode.java
 *
 * Created on 5 June 2005, 13:46
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor;
import campaigneditor.arguments.Argument;
import campaigneditor.arguments.CampaignPointerArgument;
import campaigneditor.arguments.NodePointerArgument;
import campaigneditor.arguments.NodePointerListArgument;
import campaigneditor.arguments.SpeechArgument;
import campaigneditor.arguments.StringArgument;

/**
 *
 * @author Daniel Aleksandrow
 */
public class CampaignNode extends AbstractCampaignNode {
    private Argument[] arguments = new Argument[7];
    private String name = "Campaign Node";
    private String description = "Campaign Node";
    
    public CampaignNode()
    {
        this.resetArguments();
        System.out.println("CampaignNode Object Created.");
    }
    
    public void resetArguments()
    {
        Argument[] args = { new CampaignPointerArgument("Campaign"),new StringArgument("Preconditions"),new SpeechArgument("Text"),new StringArgument("Spritelink"),new StringArgument("Script"),new NodePointerArgument("Contingency"),new NodePointerListArgument("Subnodes") };
        this.setArgList(args);
    }
    public void setArgList(Argument[] newargs)
    {
        for (int i = 0 ; i < this.arguments.length ; i++)
        {
            if (this.arguments[i] != null)
            {
                newargs[i].setLabel(this.arguments[i].getLabel());
            }
            this.arguments[i] = newargs[i];
        }
    }
    public Argument[] getArgList()
    {
        return this.arguments;
    }
    public void setName(String name)
    {
        this.name = name;
    }
    public String getName()
    {
        return this.name;
    }
    public void setDescription(String description)
    {
        this.description = description;
    }
    public String getDescription()
    {
        return this.description;
    }
}
