/* A general game class to allow for the use of instance variables like in Java
 * main.cpp will essentially serve as the container for main() and calls
 * this class for all practical intents and purposes
 *
 * Author: Kyle Michel
 * Date: 09/26/2013
 */

#include <iostream>
#include "Room.h"
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iterator>

#ifndef GAME
#define GAME

using namespace std;

class Game {
 public:
  Game();
  bool run(void);
 private:
  Game(Game& copy);
  bool done;
  bool running;
};
#endif
