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
  arrDimensions = new vector<int>();
  if (setupArrays() == MEM_ALLOC_FAIL) {
    commandWords = NULL;
  }
  else {
    //Print contents of commandWords
    for(int i = 0; i < (*arrDimensions)[0]; i++) {
      for (int j = 0; j < (*arrDimensions)[i+1]; j++) {
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
  arrDimensions->push_back(numCmds);
  commandWords = new (nothrow) string*[numCmds];
  if (commandWords == NULL) {
    return MEM_ALLOC_FAIL;
  }
  tinyxml2::XMLNode* current = commandListRoot->FirstChild();
  for (int i = 0; i < numCmds; i++) {
    int numWords = countChildren(current);
    arrDimensions->push_back(numWords);
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

/* Takes a raw input string from the user and produces a machine-
 * readable version containing simply unordered nouns and verbs.
 * For now, multi-word objects and commands will need to be specified
 * with '-' characters. Returns true if the string has at least one
 * verb (command).
 */
bool Parser::parseCommand(string input, vector <string>* tokens) {
  tokenize(input,tokens);
  //convert all words to their "Main" version
  for (int i = 0; i < tokens->size(); i++) {
    string mainw = getMainWord((*tokens)[i]);
    if (mainw.compare("") == 0) {
      tokens->erase(tokens->begin()+i);
    }
    else {
      (*tokens)[i] = mainw;
    }
  }
  return true;
  //At this point, tokens should contain a list of valid command
  //words and items specified.
}

/* A function that breaks apart a string by spaces, taking advantage
 * of the string stream interface, storing the results in tokens.
 */
void Parser::tokenize(string full, vector <string>* tokens) {
  string buf; // Have a buffer string
  stringstream ss(full); // Insert the string into a stream
  string s;
  while(getline(ss,s,' ')) {
    tokens->push_back(s);
  }
}

/* Takes a single word parameter and returns the "official" version
 * of the word that the game will recognize. As well, it throws out
 * any words not recognized by the game by returning an empty string.
 */
string Parser::getMainWord(string str) {
  for(int i = 0; i < (*arrDimensions)[0]; i++) {
    for (int j = 0; j < (*arrDimensions)[i+1]; j++) {
	if (str.compare(commandWords[i][j]) == 0) {
	  return commandWords[i][0];
	}
      }
    }
  return "";
}
