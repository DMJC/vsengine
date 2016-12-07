/* 
 * Vega Strike
 * Copyright (C) 2001-2002 Daniel Horn
 * 
 * http://vegastrike.sourceforge.net/
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/*
  easyDom - easy DOM for expat - written by Alexander Rawass <alexannika@users.sourceforge.net>
*/

#ifndef _EASYDOM_H_
#define _EASYDOM_H_

#include <expat.h>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include "xml_support.h"

using std::string;
using std::vector;
using std::stack;
using std::ostream;

using XMLSupport::AttributeList;

extern string parseCalike(char const *filename);

class easyDomNode {
 public:
  easyDomNode();

  void set(easyDomNode *parent,string name,  AttributeList *attributes);
  void printNode(ostream& out,int recurse_level,int level);

  void addChild(easyDomNode *child);

  string Name() { return name ; }

  void set_attribute(string name,string value) { attribute_map[name]=value; };

  string attr_value(string attr_name);
  vector<easyDomNode *> subnodes;

 private:
  easyDomNode *parent;
  AttributeList *attributes;

  map<string,string> attribute_map;

  //vector<string> att_name;
  //vector<string> att_value;

  string name;
};

typedef map<string,int> tagMap;

class tagDomNode : public easyDomNode {
 public:
  int tag;

  void Tag(tagMap *tagmap) { 
    tag=(*tagmap)[Name()];
    if(tag==0){
      cout << "cannot translate tag " << Name() << endl;
    }

    vector<easyDomNode *>::const_iterator siter;
  
    for(siter= subnodes.begin() ; siter!=subnodes.end() ; siter++){
      tagDomNode *tnode=(tagDomNode *)(*siter);
      tnode->Tag(tagmap);
    }

  };

};


template<class domNodeType> class easyDomFactory {
 public:
  easyDomFactory() {};

  void getColor(char *name, float color[4]);
  char *getVariable(char *section,char *name);

  void c_alike_to_xml(const char *filename);

  struct easyDomFactoryXML {
  } *xml;

    domNodeType *LoadXML(const char *filename) {

  const int chunk_size = 16384;

  FILE * inFile = fopen (filename, "r");
  if(!inFile) {
    //cout << "warning: could not open file: " << filename << endl;
    //    assert(0);
    return NULL;
  }

  xml = new easyDomFactoryXML;

  XML_Parser parser = XML_ParserCreate(NULL);
  XML_SetUserData(parser, this);
  XML_SetElementHandler(parser, &easyDomFactory::beginElement, &easyDomFactory::endElement);
  XML_SetCharacterDataHandler(parser,&easyDomFactory::charHandler);
  
  do {
    char *buf = (XML_Char*)XML_GetBuffer(parser, chunk_size);
    int length;

    length = fread (buf,1, chunk_size,inFile);
    //length = inFile.gcount();
    XML_ParseBuffer(parser, length, feof(inFile));
  } while(!feof(inFile));

  fclose (inFile);
  XML_ParserFree (parser);

  return (domNodeType *)topnode;
    };

  static void charHandler(void *userData, const XML_Char *s, int len){
  char buffer[2048];
  strncpy(buffer,s,len);
  // printf("XML-text: %s\n",buffer);
}
;


domNodeType *LoadCalike(const char *filename) {

  const int chunk_size = 16384;

  string module_str=parseCalike(filename);
  if(module_str.empty()) {
    //cout << "warning: could not open file: " << filename << endl;
    //    assert(0);
    return NULL;
  }

  xml = new easyDomFactoryXML;

  XML_Parser parser = XML_ParserCreate(NULL);
  XML_SetUserData(parser, this);
  XML_SetElementHandler(parser, &easyDomFactory::beginElement, &easyDomFactory::endElement);
  XML_SetCharacterDataHandler(parser,&easyDomFactory::charHandler);
  
  int index=0;
  int string_size=module_str.size();
  int incr=chunk_size-2;
  int is_final=false;

  do {
    char *buf = (XML_Char*)XML_GetBuffer(parser, chunk_size);

    int max_index=index+incr;
    int newlen=incr;

    printf("max_index=%d,string_size=%d\n",max_index,string_size);
    if(max_index>=string_size){
      newlen=module_str.size()-index;
      printf("getting string from %d length %d\n",index,newlen);
      const char *strbuf=module_str.substr(index,newlen).c_str();
      strncpy (buf,strbuf,newlen);
    }
    else{
      printf("getting string from %d length %d\n",index,incr);
      const char *strbuf=module_str.substr(index,incr).c_str();
      strncpy (buf,strbuf,incr);
      newlen=incr;
    }

    index+=newlen;

    if(index>=string_size){
      is_final=true;
    }

    XML_ParseBuffer(parser, newlen, is_final);
  } while(!is_final);

  XML_ParserFree (parser);

  return (domNodeType *)topnode;
    };




  static void beginElement(void *userData, const XML_Char *name, const XML_Char **atts){
  ((easyDomFactory*)userData)->beginElement(name, AttributeList(atts));
};
  static void endElement(void *userData, const XML_Char *name){
  ((easyDomFactory*)userData)->endElement(name);
}
;

  void beginElement(const string &name, const AttributeList &attributes){
  AttributeList::const_iterator iter;

  domNodeType *parent;

  if(nodestack.empty()){
    parent=NULL;
  }
  else{
    parent=nodestack.top();
  }

  domNodeType *thisnode=new domNodeType();
  thisnode->set(parent,name,(AttributeList *) &attributes);

  for(iter = attributes.begin(); iter!=attributes.end(); iter++) {
    //cout <<  name << "::" << (*iter).name << endl;
  }

  if(parent==NULL){
    topnode=thisnode;
  }
  else{
    parent->addChild(thisnode);
  }
  nodestack.push(thisnode);

};

  void endElement(const string &name){

  domNodeType *stacktop=nodestack.top();

  if(stacktop->Name()!=name){
    cout << "error: expected " << stacktop->Name() << " , got " << name << endl;
    exit(0);
  }
  else{
    nodestack.pop();
  }
  
}
;

  stack<domNodeType *> nodestack;

  domNodeType *topnode;
};

#endif // _EASYDOM_H_
