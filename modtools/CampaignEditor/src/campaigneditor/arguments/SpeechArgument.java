/*
 * SpeechArgument.java
 *
 * Created on February 15, 2007, 9:36 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package campaigneditor.arguments;

import campaigneditor.AbstractCampaignNode;
import campaigneditor.CampaignNodeFactory;
import java.util.ArrayList;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 *
 * @author daniel
 */
public class SpeechArgument implements Argument
{
    private String name = "";
    private String[][] value = new String[0][0];
    /** Creates a new instance of StringArgument */
    public SpeechArgument(String label)
    {
        this.setLabel(label);
    }
    public SpeechArgument()
    {
        this.setLabel("TextArgument");
    }
    public Element toXml(Document doc)
    {
        Element element = doc.createElement("Speech");
        Element line;
        for (String[] lineset : this.value)
        {
            line = doc.createElement("SpeechLine");
            line.appendChild(doc.createAttribute("Header"));
            line.setAttribute("Header",lineset[0]);
            line.appendChild(doc.createTextNode(lineset[1]));
            element.appendChild(line);
        }
        return element;
    }
    public void fromXml(Element node)
    {
        ArrayList importTemp = new ArrayList();
        
        NodeList argumentnodes = node.getChildNodes();
        
        String[] line = new String[2];
        
        for (int i = 0 ; i < argumentnodes.getLength() ; i++)
        {
            if (argumentnodes.item(i).getNodeType() == Node.ELEMENT_NODE)
            {
                line[0] = argumentnodes.item(i).getAttributes().getNamedItem("Header").toString();
                // I know this node has a textnode as a child, but this way is easy enough
                line[1] = argumentnodes.item(i).getTextContent();
                // will this clone it and allow reuse? only a test will tell
                importTemp.add(line);
            }
        }
        this.setValue((String[][]) importTemp.toArray(new String[0][0]));
    }
    public void setLabel(String label)
    {
        this.name = label;
    }
    public String getLabel()
    {
        return this.name;
    }
    public void setValue(String[][] value)
    {
        this.value = value;
    }
    public String[][] getValue()
    {
        return this.value;
    }
    public Argument clone()
    {
        SpeechArgument clone = new SpeechArgument(this.name);
        clone.setValue(this.value.clone());
        return (Argument) clone;
    }
}
