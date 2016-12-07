/*
 * BooleanArgument.java
 *
 * Created on October 14, 2005, 8:24 PM
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
public class BooleanArgument implements Argument
{
    private String name;
    private boolean value;
    /** Creates a new instance of BooleanArgument */
    public BooleanArgument(String label)
    {
        this.setLabel(label);
    }
    public BooleanArgument()
    {
        this.setLabel("BooleanArgument");
    }
    public Element toXml(Document doc)
    {
        Element element = doc.createElement("Boolean");
        element.appendChild(doc.createTextNode(Boolean.toString(this.value)));
        return element;
    }
    public void fromXml(Element node)
    {
        this.setValue((new Boolean(node.getTextContent()).booleanValue()));
    }
    public void setLabel(String label)
    {
        this.name = label;
    }
    public String getLabel()
    {
        return this.name;
    }
    public void setValue(boolean value)
    {
        this.value = value;
    }
    public boolean getValue()
    {
        return this.value;
    }
    public Argument clone()
    {
        BooleanArgument clone = new BooleanArgument(this.name);
        clone.setValue(this.value);
        return (Argument) clone;
    }
}
