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

using namespace std;
//Reads all the keywords from appropriate text files (we run a clean
//establishment) and stores them to coorisponding arrays, helping to organize
//all the possible combinations of words in the English language.
Parser::Parser() {
  currentFile.open("keywords.txt");
  if (currentFile.is_open()) {
    addToVect();
  }
}

void Parser::addToVect() {
  string line;
  while (getline(currentFile,line)) {
    vector <int> params = getParams(line);    
    for (int i = 0; i < params.size(); i++) {
      for (int j = 0; j < NUMBER_OF_CATEGORIES; j++) {
	if (params[i] == j) {
	  words[j].push_back(line.substr(params.size()*2+1,line.length()-(params.size()*2)-1));
	}
      }
    }
  }
}

vector <int> Parser::getParams(string line) {
  int i = 0;
  vector <int> ret;
  while (line[i] != '\0') {
    if (line[i] == '@') {
      i++;
      ret.push_back((int) line[i]-'0');
    }
    i++;
  }
  return ret;
}

string Parser::charToString(char c) {
  stringstream ss;
  string s;
  ss << c;
  ss >> s;
  return s;
}

bool Parser::isValidName(string test,string str) {
  vector <string> tokens;
  //split
  string word;
  stringstream ss(str);
  while (getline(ss,word,'%')) {
    tokens.push_back(word);
  }
  for(int i = 0; i < tokens.size(); i++) {
    if (test == tokens[i]) {
      return true;
    }
  }
  return false;
}

vector <string> Parser::parseCommand(string input) {
  vector <string> tokens;
  int idxflag = 0;//Starting point for the substring
  int currentlength = 1;
  //Test for keywords by starting at the first word and expanding the substring until one
  //is found or it reaches the null character. Repeats this process from the start of every
  //word in the command.
  while (input[idxflag] != '\0') {
    while (input.length() - idxflag != currentlength) {
      bool found = false;
      for (int i = 0; i < NUMBER_OF_CATEGORIES; i++) {
	for (int j = 0; j < words[i].size(); j++) {
	  if (isValidName(input.substr(idxflag,currentlength),words[i][j])) {
	    if (i == DIRECTION) {
	      tokens.push_back("move");
	    }
	    tokens.push_back(getMainWord(words[i][j]));
	    idxflag = idxflag + currentlength;
	    currentlength = 1;
	    found = true;
	    break;
	  }
	}
	if (found == true) {
	  break;
	}
      }
      currentlength++;
    }
    idxflag++;
  }
}
  
string Parser::getMainWord(string str) {
  return str.substr(0,str.find('%')-1);
}
