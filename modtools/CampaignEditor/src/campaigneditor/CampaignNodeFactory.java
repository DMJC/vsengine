/*
 * CampaignNodeFactory.java
 *
 * Created on 18 July 2005, 20:52
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor;

/**
 *
 * @author Daniel Aleksandrow
 */
public class CampaignNodeFactory {
    
    public static enum CampaignNodeType { CargoMission, NoFailureCargoMission, CampaignNode };
    
    /** Creates a new instance of CampaignNodeFactory */
    public static AbstractCampaignNode getCampaignNode(CampaignNodeType e)
    {
        switch(e)
        {
            case CargoMission:
                return new CargoMission();
            case NoFailureCargoMission:
                return new CampaignNode();//FIXME
            default:
                return new CampaignNode();
        }
    }
    
    public static AbstractCampaignNode getCampaignNode(String name)
    {
        CampaignNodeType nodetype = CampaignNodeFactory.CampaignNodeType.valueOf(name);
        return CampaignNodeFactory.getCampaignNode(nodetype);
    }
    
}
