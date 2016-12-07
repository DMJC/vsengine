/*
 * NodePointerListArgument.java
 *
 * Created on September 26, 2005, 1:18 PM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor.arguments;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;

/**
 *
 * @author daniel
 */
public class NodePointerListArgument implements Argument
{

    private String name = "";
    private NodePointerArgument[] values = new NodePointerArgument[0];
    /**
     * Creates a new instance of NodePointerArgument 
     */
    public NodePointerListArgument(String label)
    {
        this.setLabel(label);
    }
    public NodePointerListArgument()
    {
        this.setLabel("NodePointerListArgument");
    }
    public Element toXml(Document doc)
    {
        Element element = doc.createElement("NodePointerList");
        for (int i = 0 ; i < this.values.length ; i++)
        {
            element.appendChild(this.values[i].toXml(doc));
        }
        return element;
    }
    public void fromXml(Element node)
    {
        NodePointerArgument pointer;
        this.values = new NodePointerArgument[0];
        NodePointerArgument[] pointers;
        for (int i = 0 ; i < node.getChildNodes().getLength() ; i++)
        {
            if (node.getChildNodes().item(i).getNodeType() == Node.ELEMENT_NODE)
            {
                pointer = new NodePointerArgument();
                pointer.fromXml((Element) node.getChildNodes().item(i));
                pointers = new NodePointerArgument[this.values.length+1];
                for (int j = 0 ; j < this.values.length ; j++)
                {
                    pointers[j] = this.values[j];
                }
                pointers[this.values.length] = pointer;
                this.values = pointers;
            }
        }
    }
    public void setLabel(String label)
    {
        this.name = label;
    }
    public void setValues(NodePointerArgument[] values)
    {
        this.values = values;
    }
    public void setValues(Object[] values)
    {
        NodePointerArgument[] newvalues = new NodePointerArgument[values.length];
        for (int i = 0 ; i < values.length ; i++)
        {
            newvalues[i] = (NodePointerArgument) values[i];
        }
        this.setValues(newvalues);
    }
    public String getLabel()
    {
        return this.name;
    }
    public NodePointerArgument[] getValues()
    {
        return this.values;
    }
    public Argument clone()
    {
        NodePointerListArgument newarg = new NodePointerListArgument(this.name);
        newarg.setValues(this.values);
        return (Argument) newarg;
    }
    private void addValue(NodePointerArgument pointer)
    {
        NodePointerArgument[] newargs = new NodePointerArgument[this.values.length+1];
        for (int i = 0 ; i < this.values.length ; i++)
        {
            newargs[i] = this.values[i];
        }
        newargs[this.values.length] = pointer;
        this.values = newargs;
    }
}
