/*
 * StringArgument.java
 *
 * Created on September 21, 2005, 9:35 PM
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
public class StringArgument implements Argument
{
    private String name = "";
    private String value = "";
    /** Creates a new instance of StringArgument */
    public StringArgument(String label)
    {
        this.setLabel(label);
    }
    public StringArgument()
    {
        this.setLabel("StringArgument");
    }
    public Element toXml(Document doc)
    {
        Element element = doc.createElement("String");
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
    public String getLabel()
    {
        return this.name;
    }
    public void setValue(String value)
    {
        this.value = value;
    }
    public String getValue()
    {
        return this.value;
    }
    public Argument clone()
    {
        StringArgument clone = new StringArgument(this.name);
        clone.setValue(this.value);
        return (Argument) clone;
    }
}
