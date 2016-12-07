/*
 * NodePointerArgument.java
 *
 * Created on September 22, 2005, 8:17 PM
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
public class NodePointerArgument implements Argument
{

    private String name = "";
    private String value = "";
    /**
     * Creates a new instance of NodePointerArgument 
     */
    public NodePointerArgument(String label)
    {
        this.setLabel(label);
    }
    public NodePointerArgument()
    {
        this.setLabel("NodePointerArgument");
    }
    public Element toXml(Document doc)
    {
        Element element = doc.createElement("NodePointer");
        element.appendChild(doc.createTextNode(this.value));
        return element;
    }
    public void fromXml(Element node)
    {
        this.setValue(node.getTextContent());
    }
    public void setLabel(String label)
    {
        this.name = label;
    }
    public void setValue(String value)
    {
        this.value = value;
    }
    public String getLabel()
    {
        return this.name;
    }
    public String getValue()
    {
        return this.value;
    }
    public String toString()
    {
        return this.getValue();
    }
    public boolean equals(Object oode)
    {
        try{
            NodePointerArgument node = (NodePointerArgument) oode;
            return this.getValue().equals(node.getValue());
        }
        catch (Exception e)
        {
//            e.printStackTrace();
            return false;
        }
        }
    public Argument clone()
    {
        NodePointerArgument newarg = new NodePointerArgument(this.name);
        newarg.setValue(this.value);
        return (Argument) newarg;
    }
}