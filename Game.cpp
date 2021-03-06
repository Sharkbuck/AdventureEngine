/* A general game class to allow for the use of fields like in Java
 * main.cpp will essentially serve as the container for main() and calls
 * this class for all practical intents and purposes
 *
 * Author: Kyle Michel
 * Date: 09/26/2013
 */

#include "Game.h"
#include "Room.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

Game::Game() {
  running = true;
  this->run();
}

//Main running loop to run the entire game

bool Game::run() {
  while (running) {
      cout << "This works." << endl;
  }
  if (done == true) {
    return false;
  }
  return true;
}

