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
  std::cout << "Zuul II v.0.3 Booted.\nType \"help\" if you're in trouble or this is your first time playing" << std::endl;
  Parser* pars = new Parser();
  std::cout << "\n---------------------------\n>";
  std::string in;
  std::getline(std::cin, in);
  std::vector<std::string> results;
  pars->parseCommand(in,&results);
  for (int i = 0; i < results.size(); i++) {
    std::cout << results[i] << std::endl;
  }
  std::cout << "run successful." << std::endl;
  return 0;
}
