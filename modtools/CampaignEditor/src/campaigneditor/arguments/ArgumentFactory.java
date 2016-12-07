/*
 * ArgumentFactory.java
 *
 * Created on September 22, 2005, 12:46 PM
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor.arguments;




/**
 *
 * @author daniel
 */
public class ArgumentFactory
{
    public static enum ArgumentType { NodePointerListArgument, SpriteLinkArgument, NodePointerArgument, CampaignPointerArgument, StringArgument, IntegerArgument, BooleanArgument, CargoArgument, ConditionsArgument, CargoNameQuantityArgument, SpeechArgument, ArgumentArgument /*Just for testing*/ };

/** Given an ArgumentType, returns the corresponding Argument object. */
    public static Argument getArgument(ArgumentType e)
    {
        switch(e)
        {
            case StringArgument:
                return new StringArgument();
            case IntegerArgument:
                return new IntegerArgument();
            case BooleanArgument:
                return new BooleanArgument();
            case CampaignPointerArgument:
                return new CampaignPointerArgument();
            case NodePointerArgument:
                return new NodePointerArgument();
            case NodePointerListArgument:
                return new NodePointerListArgument();
            case CargoArgument:
                return new CargoArgument();
            case CargoNameQuantityArgument:
                return new CargoNameQuantityArgument();
            case SpeechArgument:
                return new SpeechArgument();
            default:
                return new StringArgument();
        }
    }

/** Given an String naming the Argument type, returns the corresponding Argument object. */
    public static Argument getArgument(String name)
    {
        ArgumentType argtype = ArgumentFactory.ArgumentType.valueOf(name+"Argument");
        return ArgumentFactory.getArgument(argtype);
    }
}
