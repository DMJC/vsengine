/*
 * ArgumentDisplayFactory.java
 *
 * Created on September 21, 2005, 11:12 PM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor.display;
import campaigneditor.arguments.Argument;
import campaigneditor.arguments.ArgumentFactory.ArgumentType;
import campaigneditor.arguments.ArgumentFactory;
import campaigneditor.arguments.BooleanArgument;
import campaigneditor.arguments.CargoArgument;



/**
 *
 * @author Daniel Aleksandrow
 */
public class ArgumentDisplayFactory {
        
    /** Creates a new instance of ArgumentDisplayFactory */
    public static ArgumentDisplay getArgumentDisplay(ArgumentType e)
    {
        switch(e)
        {
            case StringArgument:
                return new StringArgumentDisplay();
            case IntegerArgument:
                return new IntegerArgumentDisplay();
            case BooleanArgument:
                return new BooleanArgumentDisplay();
            case CampaignPointerArgument:
                return new CampaignPointerArgumentDisplay();
            case NodePointerArgument:
                return new NodePointerArgumentDisplay();
            case NodePointerListArgument:
                return new NodePointerListArgumentDisplay();
            case CargoArgument:
                return new CargoArgumentDisplay();
            case CargoNameQuantityArgument:
                return new CargoNameQuantityArgumentDisplay();
            case SpeechArgument:
                return new SpeechArgumentDisplay();
//            case IntegerArgument:
//                return new IntegerArgumentDisplay((IntegerArgument) a);
            default:
                return new StringArgumentDisplay();
        }
    }

    public static ArgumentDisplay getArgumentDisplay(String name)
    {
        ArgumentType nodetype = ArgumentFactory.ArgumentType.valueOf(name);
        return ArgumentDisplayFactory.getArgumentDisplay(nodetype);
    }
    
    public static ArgumentDisplay getArgumentDisplay(Argument argument)
    {
        System.out.println(argument.getClass().getSimpleName());
        ArgumentDisplay argumentdisplay = ArgumentDisplayFactory.getArgumentDisplay(argument.getClass().getSimpleName());
        argumentdisplay.setArgument(argument);
        return argumentdisplay;
    }
    
}
