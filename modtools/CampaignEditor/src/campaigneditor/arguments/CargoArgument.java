/*
 * CargoArgument.java
 *
 * Created on October 14, 2005, 9:42 PM
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
public class CargoArgument implements Argument
{
    private String name = "";
    private String value = "";
    /** Creates a new instance of CargoArgument */
    public CargoArgument(String label)
    {
        this.setLabel(label);
    }
    public CargoArgument()
    {
        this.setLabel("CargoArgument");
    }
    public Element toXml(Document doc)
    {
        Element element = doc.createElement("Cargo");
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
        CargoArgument clone = new CargoArgument(this.name);
        clone.setValue(this.value);
        return (Argument) clone;
    }
}
