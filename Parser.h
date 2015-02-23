/* Header file for Parser.cpp
 *
 * Author: Kyle Michel
 * Date: 01/22/2014
 */

#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include "tinyxml2.h"

#ifndef PARSER
#define PARSER

//DEM #defines. Bitches be mirin'.
#define NUMBER_OF_CATEGORIES 9
#define IITEM 0
#define RITEM 1
#define DIRECTION 2
#define COMMAND 3
#define EATABLE 4
#define BOOK 5
#define WEAPON 6
#define MOVABLE 7
#define USABLE 8
#define MEM_ALLOC_FAIL -1

//Class definition
class Parser {
 public:
  Parser();
  bool parseCommand(std::string input, std::vector<std::string>* tokens);
 private:
  //Copy constructor placed here to avoid making copies of the object #pointers4lyfe
  Parser(Parser &copy);
  void addToVect();
  std::vector <int> getParams(std::string line);
  std::string charToString(char c);
  bool isValidName(std::string test, std::string str);
  std::string getMainWord(std::string str);
  std::ifstream currentFile;
  std::string** commandWords;
  int setupArrays();
  int countChildren(tinyxml2::XMLNode* parent);
  void tokenize(std::string full, std::vector<std::string>* tokens);
  std::vector<int>* arrDimensions;
};

#endif
