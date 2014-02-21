/* A virtual room in a text-based adventure game
 *
 * Author: King Henry VIII
 * Date: 10/22/2012
 */
#ifndef ROOM
#define ROOM
#include <string>
#include <map>
#include <vector>

using namespace std;

class Room {
  map<string,Room*> neighbors;
  string name;
  string description;
  vector <string> exits;
  vector <string> items;
 public:
  Room(string newname, string newdescription);
  void setExit(string direction, Room* newexit);
  void setItem(string newitem);
  void setName(string newname);
  void setDescription(string newdescription);
  string getName(void);
  string getDescription(void);
  vector <string> getExits(void);
  Room * getExit(string direction);
  vector <string> getItems(void);
  void removeItem(string ritem);
 private:
  //Copy Constructor (Throws an error for trying to make a copy)
  Room(Room &copy);
};
#endif


