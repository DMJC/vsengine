/*
 * IntegerArgument.java
 *
 * Created on September 21, 2005, 11:24 PM
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
 * @author Daniel Aleksandrow
 */
public class IntegerArgument implements Argument
{
    private String name;
    private int value;
    /** Creates a new instance of IntegerArgument */
    public IntegerArgument(String label)
    {
        this.setLabel(label);
    }
    public IntegerArgument()
    {
        this.setLabel("IntegerArgument");
    }
    public Element toXml(Document doc)
    {
        Element element = doc.createElement("Integer");
        element.appendChild(doc.createTextNode(Integer.toString(this.value)));
        return element;
    }
    public void fromXml(Element node)
    {
        this.setValue((new Integer(node.getTextContent()).intValue()));
    }
    public void setLabel(String label)
    {
        this.name = label;
    }
    public String getLabel()
    {
        return this.name;
    }
    public void setValue(int value)
    {
        this.value = value;
    }
    public int getValue()
    {
        return this.value;
    }
    public Argument clone()
    {
        IntegerArgument clone = new IntegerArgument(this.name);
        clone.setValue(this.value);
        return (Argument) clone;
    }
}
