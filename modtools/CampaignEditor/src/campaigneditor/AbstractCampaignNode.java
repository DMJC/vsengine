/*
 * AbstractCampaignNode.java
 *
 * Created on September 22, 2005, 12:16 PM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor;

import campaigneditor.arguments.Argument;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * @author daniel
 */
public abstract class AbstractCampaignNode
{

    public String toString()
    {
        return this.getName();
    }
    
    public Element toXml(Document doc)
    {
        Element element = doc.createElement(this.getClass().getSimpleName());
        element.setAttribute("name", this.toString());
        element.setAttribute("description", this.getDescription());
        Argument[] args = this.getArgList();//to make sure all are strings
        for (int i = 0 ; i < args.length ; i++)
        {
            element.appendChild(args[i].toXml(doc));
            System.out.println(" + "+args[i].toXml(doc).getNodeName()+", Children: "+args[i].toXml(doc).getChildNodes().getLength());
        }
        return element;
    }
    public abstract void setName(String newname);
    
    public abstract String getName();
    
    public abstract void setDescription(String newdescription);
    
    public abstract String getDescription();
    
    /** Gets a list of Argument objects. */
    public abstract Argument[] getArgList();

    public abstract void setArgList(Argument[] arguments);

    public abstract void resetArguments();

}