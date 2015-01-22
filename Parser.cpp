/* A parser class for Zuul 2. This will make understanding and using user input
 * easier for the sad programmer who has to develop all this. Much cake to him.
 * And Jim. Jim too.
 *
 * Author: Kyle Michel
 * Date: 01/22/2014
 */

#include <stdlib.h>
#include <string>
#include <fstream>
#include "Parser.h"
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iostream>
#include "tinyxml2.h"
#include <new>

using namespace std;


//establishment) and stores them to coorisponding arrays, helping to organize
//all the possible combinations and iterations of words in the English 
//language.
Parser::Parser() {
  if (setupArrays() == MEM_ALLOC_FAIL) {
    commandWords = NULL;
  }
  else {
    //Print contents of commandWords
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
	cout << commandWords[i][j] << endl;
      }
    }
  }
}


int Parser::setupArrays() {
  tinyxml2::XMLDocument keywordsXML;
  keywordsXML.LoadFile("keywords.xml");
  tinyxml2::XMLNode* commandListRoot = keywordsXML.FirstChildElement("Keywords")->FirstChild();
  int numCmds = countChildren(commandListRoot);
  commandWords = new (nothrow) string*[numCmds];
  if (commandWords == NULL) {
    return MEM_ALLOC_FAIL;
  }
  tinyxml2::XMLNode* current = commandListRoot->FirstChild();
  for (int i = 0; i < numCmds; i++) {
    int numWords = countChildren(current);
    commandWords[i] = new (nothrow) string[numWords];
    if (commandWords[i] == NULL) {
      return MEM_ALLOC_FAIL;
    }
    //Write to array
    tinyxml2::XMLNode* child = current->FirstChild();
    for (int j = 0; j < numWords; j++) {
      commandWords[i][j] = child->FirstChild()->Value();
      child = child->NextSibling();
    }
    current = current->NextSibling();
    if (current == NULL) {
      break;
    }
  }
  return 0;
}

/* Takes an element in an XML file (parent) in the form 
 * of a XMLNode and returns the value of the number of
 * sub-elements directly beneath it (children).
 */
int Parser::countChildren(tinyxml2::XMLNode* parent) {
  if (parent == NULL) {
    return -1;
  }
  int count = 0;
  tinyxml2::XMLNode* current = parent->FirstChild();
  do {
    count++;
  }while (current = current->NextSibling());
  return count;
}
