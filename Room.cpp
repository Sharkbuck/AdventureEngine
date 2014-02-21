/* A class that will serve as a virtual "room" in a text-based adventure game
 *
 * Author: Kyle Michel
 * Date: 10/18/2012
 */

#include "Room.h"
#include <map>
#include <vector>
#include <string>

using namespace std;

Room::Room(string newname, string newdescription) {
  name = newname;
  description = newdescription;
}
void Room::setExit(string direction, Room *newexit) {
  neighbors[direction] = newexit;
  exits.push_back(direction);
}
void Room::setItem(string newitem) {
  items.push_back(newitem);
}
void Room::setName(string newname) {
  name = newname;
}
void Room::setDescription(string newdescription) {
  description = newdescription;
}
string Room::getName() {
  return name;
}
string Room::getDescription() {
  return description;
}
vector <string> Room::getExits() {
  return exits;
}
Room* Room::getExit(string direction) {
  return neighbors[direction];
}
vector <string> Room::getItems() {
  return items;
}
void Room::removeItem(string ritem) {
  int index = -1;
  for(int ii = 0; ii < items.size(); ii++) {
    if (ritem == items[ii]) {
      index = ii;
    }
  }
  items.erase(items.begin() + index);
}