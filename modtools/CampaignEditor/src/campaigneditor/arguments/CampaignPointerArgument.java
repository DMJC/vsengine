/*
 * CampaignPointerArgument.java
 *
 * Created on September 22, 2005, 5:29 PM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor.arguments;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * @author daniel
 */
public class CampaignPointerArgument implements Argument
{

    private String name = "";
    /**
     * Creates a new instance of CampaignPointerArgument 
     */
    public CampaignPointerArgument(String label)
    {
        this.setLabel(label);
    }
    public CampaignPointerArgument()
    {
        this.setLabel("CampaignArgument");
    }
    public Element toXml(Document doc)
    {
        return doc.createElement("CampaignPointer");
    }
    public void fromXml(Element node)
    {
        return;
    }
    public void setLabel(String label)
    {
        this.name = label;
    }
    public String getLabel()
    {
        return this.name;
    }
    public Argument clone()
    {
        return (Argument) new CampaignPointerArgument(this.name);
    }
}
