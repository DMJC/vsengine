/*
 * CargoMission.java
 *
 * Created on 18 July 2005, 21:10
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor;
import campaigneditor.arguments.Argument;
import campaigneditor.arguments.StringArgument;

/**
 *
 * @author Daniel Aleksandrow
 */
public class CargoMission extends AbstractCampaignNode
{
    private Argument[] arguments = new Argument[12];
    private String name = "Cargo Mission";
    private String description = "Cargo Mission";
    
    public CargoMission()
    {
        this.resetArguments();
        System.out.println("CampaignNode Object Created.");
    }
        
    public void resetArguments()
    {
        Argument[] args = { new StringArgument("Campaign"),new StringArgument("Sprite"),new StringArgument("ConditionToBegin"),new StringArgument("ConditionToEnd"),new StringArgument("ScriptOnClick"),new StringArgument("Script"),new StringArgument("CargoNameQuantity"),new StringArgument("VarName"),new StringArgument("Speech"),new StringArgument("RejectNode"),new StringArgument("FailureNode"),new StringArgument("SuccessNode") };
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
