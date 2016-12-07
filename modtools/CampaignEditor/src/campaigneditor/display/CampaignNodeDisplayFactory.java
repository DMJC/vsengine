/*
 * CampaignNodeDisplayFactory.java
 *
 * Created on 18 July 2005, 21:35
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor.display;

import campaigneditor.CampaignNodeFactory.CampaignNodeType;
import campaigneditor.*;

/**
 *
 * @author Daniel Aleksandrow
 */
public class CampaignNodeDisplayFactory {

    /** Creates a new instance of CampaignNodeDisplayFactory */
    public static CampaignNodeDisplay getCampaignNodeDisplay(AbstractCampaignNode node, Campaign campaign) {
        String name = node.getClass().getSimpleName();//FIXME: use method used in CampaignNodeFactory
        Enum[] nodetypes = CampaignNodeFactory.CampaignNodeType.values();
        Enum e = null;
        for (int i=0 ; i < nodetypes.length ; i++)
        {
            if (name.equals(nodetypes[i].toString()))
            {
                e = nodetypes[i];
                break;
            }
        }
        //For the moment lets simply use the same viewer...not like there's any
        //specific functionality yet
        switch((CampaignNodeType) e)
        {
//            case CampaignNode:
//                CampaignNodeDisplay displaycn = new CampaignNodeDisplay(node);
//                javax.swing.JFrame framecn = new javax.swing.JFrame();
//                framecn.add(displaycn);
//                framecn.pack();
//                framecn.setVisible(true);
//                System.out.println("Created Display");
//                //display.setVisible(true);
//                break;
//            case CargoMission:
//                CargoMissionDisplay displaycm = new CargoMissionDisplay(node);
//                javax.swing.JFrame framecm = new javax.swing.JFrame();
//                framecm.add(displaycm);
//                framecm.pack();
//                framecm.setVisible(true);
//                System.out.println("Created Display");
//                //display.setVisible(true);
//                break;
            default:
                System.out.print("Creating Display ...");
                return new CampaignNodeDisplay(node, campaign);
        }
    }
    
}
