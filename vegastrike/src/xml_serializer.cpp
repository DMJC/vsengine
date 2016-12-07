#include "xml_serializer.h"
#include "cmd/unit_generic.h"
#include "cmd/images.h"
#include "vsfilesystem.h"
#include "configxml.h"
#include "vs_globals.h"
#include "vegastrike.h"
#include "networking/const.h"

///Assumes that the tag is  <Mount type=\"  and that it will finish with " ></Mount>
using namespace XMLSupport;
using namespace VSFileSystem;

std::string intStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( *input.w.i );
}
std::string uintStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( *input.w.ui );
}
std::string floatStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( *input.w.f );
}
std::string fabsFloatStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( (float) fabs( *input.w.f ) );
}
std::string absIntStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( (int) abs( *input.w.i ) );
}
std::string scaledFloatStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( (float) ( (*input.w.f)/XMLSupport::parse_float( input.str ) ) );
}

std::string angleStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( ( float( (*input.w.f)*180/3.1415926536 ) ) );
}
std::string doubleStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( (float) (*input.w.d) );
}
std::string boolStarHandler( const XMLType &input, void *mythis )
{
    if (*input.w.b)
        return "1";
    return "0";
}
std::string charStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( *input.w.c );
}
std::string ucharStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( *input.w.uc );
}
std::string negationCharStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( -(*input.w.c) );
}
std::string negationIntStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( -(*input.w.i) );
}
std::string negationFloatStarHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( -(*input.w.f) );
}
std::string stringStarHandler( const XMLType &input, void *mythis )
{
    if (!input.w.p)
        return string( "" );
    return *( (string*) (input.w.p) );
}
std::string stringHandler( const XMLType &input, void *mythis )
{
    return input.str;
}
std::string intHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( input.w.hardint );
}
std::string floatHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( input.w.hardfloat );
}
std::string lessNeg1Handler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( ( (*input.w.c) < -1 ) ? 1 : 0 );
}

std::string cloakHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( ( (*input.w.i) == -1 ) ? 1 : 0 );       //short fix
}

std::string intToFloatHandler( const XMLType &input, void *mythis )
{
    return XMLSupport::tostring( (float) ( ( (float) (*input.w.i) )/( (float) (2147483647) ) ) );
}

void XMLElement::Write( VSFileSystem::VSFile &f, void *mythis )
{
    f.Fprintf( " %s=\"%s\"", elem.c_str(), ( (*handler)(value, mythis) ).c_str() );
}
static void Tab( VSFileSystem::VSFile &f )
{
    f.Fprintf( "\t" );
}
static void Tab( VSFileSystem::VSFile &f, int level )
{
    for (int i = 0; i < level; i++)
        Tab( f );
}
void XMLnode::Write( VSFileSystem::VSFile &f, void *mythis, int level )
{
    Tab( f, level );
    f.Fprintf( "<%s", val.c_str() );
    for (unsigned int i = 0; i < elements.size(); i++)
        elements[i].Write( f, mythis );
    if ( subnodes.empty() ) {
        f.Fprintf( "/>\n" );
    } else {
        f.Fprintf( ">\n" );
        for (unsigned int i = 0; i < subnodes.size(); i++)
            subnodes[i].Write( f, mythis, level+1 );
        Tab( f, level );
        f.Fprintf( "</%s>\n", val.c_str() );
    }
}
void XMLSerializer::Write( const char *modificationname )
{
    if (modificationname)
        if (strlen( modificationname ) != 0)
            savedir = modificationname;
    VSFileSystem::CreateDirectoryHome( VSFileSystem::savedunitpath+"/"+savedir );
    VSFile  f;
    VSError err = f.OpenCreateWrite( savedir+"/"+this->filename, UnitFile );
    if (err > Ok) {
        fprintf( stderr, "!!! ERROR : Writing saved unit file : %s\n", f.GetFullPath().c_str() );
        return;
    }
    for (unsigned int i = 0; i < topnode.subnodes.size(); i++)
        topnode.subnodes[i].Write( f, mythis, 0 );
    f.Close();
}

static string TabString( int level )
{
    string ret = "";
    for (int i = 0; i < level; i++)
        ret += '\t';
    return ret;
}
string XMLSerializer::WriteString()
{
    string ret = "";
    for (unsigned int i = 0; i < topnode.subnodes.size(); i++)
        ret += topnode.subnodes[i].WriteString( mythis, 0 );
    return ret;
}
string XMLnode::WriteString( void *mythis, int level )
{
    string ret;
    char   buffer[MAXBUFFER];
    memset( buffer, 0, MAXBUFFER );
    ret  = TabString( level );
    ret  = ret+"<"+val;
    ret += string( buffer );
    for (unsigned int i = 0; i < elements.size(); i++)
        ret += elements[i].WriteString( mythis );
    if ( subnodes.empty() ) {
        ret += "/>\n";
    } else {
        ret += ">\n";
        for (unsigned int i = 0; i < subnodes.size(); i++)
            ret += subnodes[i].WriteString( mythis, level+1 );
        ret += TabString( level );
        ret  = ret+"</"+val+">\n";
    }
    return ret;
}
string XMLElement::WriteString( void *mythis )
{
    string ret( " "+elem+"=\""+( (*handler)(value, mythis) )+"\"" );
    return ret;
}

XMLSerializer::XMLSerializer( const char *filename, const char *modificationname, void *mythis ) : savedir( modificationname )
    , mythis( mythis )
{
    curnode = &topnode;
    //In network mode we don't care about saving filename, we want always to save with modification
    //name since we only work with savegames
    if (Network != NULL)
        this->filename = string( modificationname );
    else
        this->filename = string( filename );
}
void XMLSerializer::AddTag( const std::string &tag )
{
    curnode->subnodes.push_back( XMLnode( tag, curnode ) );
    curnode = &curnode->subnodes.back();
}

void XMLSerializer::AddElement( const std::string &element, XMLHandler *handler, const XMLType &input )
{
    curnode->elements.push_back( XMLElement( element, input, handler ) );
}

void XMLSerializer::EndTag( const std::string endname )
{
    if (curnode)
        if (endname == curnode->val)
            curnode = curnode->up;
}

