/*
 * Campaign.java
 *
 * Created on 5 June 2005, 13:54
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor;

import campaigneditor.arguments.Argument;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import campaigneditor.arguments.ArgumentFactory;

/**
 *
 * @author Daniel Aleksandrow
 */
public class Campaign {
    
    private String name;
    private AbstractCampaignNode[] nodelist = new AbstractCampaignNode[0];
    public static String GENERICCAMPAIGNNAME = "Campaign";
    
    /** Creates a new instance of Campaign */
    public Campaign()
    {
        this.name = this.GENERICCAMPAIGNNAME;
    }
    public Campaign(String name)
    {
        this.name = name;
    }
    public Campaign(String name, AbstractCampaignNode[] nodelist)
    {
        this.name = name;
        this.nodelist = nodelist;
    }
    
    public AbstractCampaignNode[] getNodeList()
    {
        return this.nodelist;
    }
    
    public void addNode(AbstractCampaignNode newnode)
    {
        AbstractCampaignNode[] newlist = new AbstractCampaignNode[this.nodelist.length+1];
        for (int i = 0; i < this.nodelist.length; i++)
        {
            newlist[i] = this.nodelist[i];
        }
        newlist[newlist.length-1] = newnode;
        this.nodelist = newlist;
    }
    public void addNode(Node newnode)
    {
        if (newnode.getNodeType() != Node.ELEMENT_NODE)
        {
            return;
        }
        String name = newnode.getAttributes().getNamedItem("name").getNodeValue();
        String description = newnode.getAttributes().getNamedItem("description").getNodeValue();
        NodeList argumentnodes = newnode.getChildNodes();
        Argument[] arguments = new Argument[0];
        for (int i = 0 ; i < argumentnodes.getLength() ; i++)
        {
            if (argumentnodes.item(i).getNodeType() == Node.ELEMENT_NODE)
            {
                System.out.println("Adding Argument "+argumentnodes.item(i).getNodeName());
                Argument[] newarguments = new Argument[arguments.length+1];
                for (int j = 0 ; j < arguments.length ; j++)
                {
                    newarguments[j] = arguments[j];
                }
                newarguments[arguments.length] = ArgumentFactory.getArgument(argumentnodes.item(i).getNodeName());
                newarguments[arguments.length].fromXml((Element) argumentnodes.item(i));
                arguments = newarguments;
            }
        }
        AbstractCampaignNode campaignnode = CampaignNodeFactory.getCampaignNode(newnode.getNodeName());
        campaignnode.setName(name);
        campaignnode.setDescription(description);
        campaignnode.setArgList(arguments);
        this.addNode(campaignnode);
        return;
    }

    public void deleteNode(AbstractCampaignNode node)
    {
        int nodeindex = -1;
        for (int i = 0 ; i < this.nodelist.length ; i++)
        {
            if (node == this.nodelist[i])
            {
                nodeindex = i;
                break;
            }
        }
        if (!(nodeindex < 0))
        {
            this.deleteNode(nodeindex);
        }
        else
        {
            System.out.println("Error:  No matching node found");
        }
    }
    
    public void deleteNode(int nodeindex)
    {
        if (nodeindex >= 0 && nodeindex < this.nodelist.length)
        {
            AbstractCampaignNode[] newlist = new AbstractCampaignNode[this.nodelist.length-1];
            for (int i = 0; i < nodeindex; i++)
            {
                newlist[i] = this.nodelist[i];
            }
            for (int i = this.nodelist.length-1; i > nodeindex; i--)
            {
                newlist[i-1] = this.nodelist[i];
            }
            this.nodelist = newlist;
        }
        else
        {
            System.out.println("Error:  Node index out of range");
        }
    }
    
    public String toString()
    {
        return this.name;
    }
    public Document toXml()
    {
        Document doc;
        try
        {
            DocumentBuilder builder = DocumentBuilderFactory.newInstance().newDocumentBuilder();
            doc = builder.newDocument();
        }
        catch (ParserConfigurationException e)
        {
            return null;
        }
        Element root = doc.createElement("CampaignData");
        Element campaign = doc.createElement("Campaign");
        campaign.setAttribute("name", this.toString());
        root.appendChild(campaign);
        doc.appendChild(root);
        for (int i = 0 ; i < this.nodelist.length ; i++)
        {
            campaign.appendChild(this.nodelist[i].toXml(doc));
        }
        return doc;
    }
    
    
}
