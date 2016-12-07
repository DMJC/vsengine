#ifndef _CMD_AISCRIPT_H_
#define _CMD_AISCRIPT_H_
#include "order.h"
#include "navigation.h"
#include "xml_support.h"

/**
 * Loads a script from a given XML file
 * FIXME: This data is not cached and is streamed
 * from harddrive and expat'ed each time a script is loaded
 */
struct AIScriptXML;
class AIScript : public Order
{
///File name the AI script takes, to be loaded upon first execute (needs ref to parent)
    char *filename;
///Temporary data to hold while AI script loads
    AIScriptXML *xml;
///Loads the XML file, filename when Execute() is called
    void LoadXML(); //load the xml
///Internal functions to expat
    static void beginElement( void *userData, const XML_Char *name, const XML_Char **atts );
///internal functions for use of expat
    static void endElement( void *userData, const XML_Char *name );
///The top float on the current stack
    float& topf();
///Rid of the top float on the current stack
    void popf();
///The top vector on the current stack
    QVector& topv();
///Pop the top vector of teh current stack
    void popv();
///member function begin elements... deals with pushing vectors on stack
    void beginElement( const string &name, const XMLSupport::AttributeList &attributes );
///member function end elements...deals with calling AI scripts from the stack
    void endElement( const string &name );
public:
///saves scriptname in the filename var
    AIScript( const char *scriptname );
    ~AIScript();
///Loads the AI script from the hard drive, or executes if loaded
    void Execute();
};

#endif

