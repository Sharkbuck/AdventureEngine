/* This will be the long awaited (my ass) sequel to one of my favorite projects
 * of all time, Zuul. The goal of this project is to create a much larger game
 * using the same game engine, but more streamlined and easier to read for
 * debugging purposes. As well, the story won't be created solely by myself this
 * time, so it might have a completely different flavor. I don't really care, so
 * long as I get my stupid jokes and references in.
 *
 * Author: Kyle Michel
 * Date: 9/22/2013
 */

#include "Game.h"
#include <iostream>
#include "Parser.h"

int main() {
  std::cout << "Zuul II v.0.2 Booted.\nType \"help\" if you're in trouble or this is your first time playing" << std::endl;
  Parser* pars = new Parser();
  string input;
  cin >> input;
  vector <string> vect = pars->parseCommand(input);
  std::cout << "run successful." << std::endl;
  return 0;
}