/*
 * CargoNameQuantityArgument.java
 *
 * Created on October 14, 2005, 7:24 PM
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
 * @author Daniel Aleksandrow
 */
public class CargoNameQuantityArgument implements Argument
{
    private String name = "";
    private CargoArgument cargo = new CargoArgument("Cargo Type");
    private IntegerArgument quantity = new IntegerArgument("Quantity");
    private BooleanArgument missioncargo = new BooleanArgument("Cargo is mission cargo?");
    /** Creates a new instance of CargoNameQuantityArgument */
    public CargoNameQuantityArgument(String label)
    {
        this.setLabel(label);
    }
    public CargoNameQuantityArgument()
    {
        this.setLabel("CargoNameQuantityArgument");
    }
    public Element toXml(Document doc)
    {
        Element element = doc.createElement("CargoNameQuantity");
        element.appendChild(this.cargo.toXml(doc));
        element.appendChild(this.quantity.toXml(doc));
        element.appendChild(this.missioncargo.toXml(doc));
        return element;
    }
    
    public void fromXml(Element node)
    {
        for (int i = 0 ; i < node.getChildNodes().getLength() ; i++)
        {
            if (node.getChildNodes().item(i).getNodeType() == Node.ELEMENT_NODE)
            {
                if (node.getChildNodes().item(i).getNodeName().equals("Cargo"))
                {
                    this.cargo = new CargoArgument();
                    this.cargo.setValue(node.getChildNodes().item(i).getTextContent());
                }
                else if (node.getChildNodes().item(i).getNodeName().equals("Integer"))
                {
                    this.quantity = new IntegerArgument();
                    this.quantity.setValue(Integer.parseInt(node.getChildNodes().item(i).getTextContent()));
                }
                else if (node.getChildNodes().item(i).getNodeName().equals("Boolean"))
                {
                    this.missioncargo = new BooleanArgument();
                    this.missioncargo.setValue(Boolean.parseBoolean(node.getChildNodes().item(i).getTextContent()));
                }
            }
        }
    }
    public void setLabel(String label)
    {
        this.name = label;
    }
    public String getLabel()
    {
        return this.name;
    }
    public void setCargo(CargoArgument cargo)
    {
        this.cargo = cargo;
    }
    public void setQuantity(IntegerArgument quantity)
    {
        this.quantity = quantity;
    }
    public void setMissionCargo(BooleanArgument missioncargo)
    {
        this.missioncargo = missioncargo;
    }
    public CargoArgument getCargo()
    {
        return this.cargo;
    }
    public IntegerArgument getQuantity()
    {
        return this.quantity;
    }
    public BooleanArgument getMissionCargo()
    {
        return this.missioncargo;
    }
    public Argument clone()
    {
        CargoNameQuantityArgument clone = new CargoNameQuantityArgument(this.name);
        clone.setCargo(this.getCargo());
        clone.setQuantity(this.getQuantity());
        clone.setMissionCargo(this.getMissionCargo());
        return (Argument) clone;
    }
}
