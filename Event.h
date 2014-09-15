/* Header file for the Event class
 *
 * Author: Kyle Michel
 * Date: September 4, 2014
 */

#ifndef EVENT
#define EVENT

class Event {
 public:
  Event();
  bool getOccured();
 private:
  Event(Event &copy);
  bool occured;
  
};
#endif
