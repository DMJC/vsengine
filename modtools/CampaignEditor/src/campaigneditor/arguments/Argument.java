/*
 * Argument.java
 *
 * Created on September 21, 2005, 9:17 PM
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
public interface Argument
{    
    public void setLabel(String label);
    
    public String getLabel();

    public Element toXml(Document doc);
    
    public void fromXml(Element node);
    
    public Argument clone();

}
