#include <lib.h>
#include "../wood.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("in the Havenwood");
  SetLong(
    "The woods open here to a small glade that serves as the Council Area "
    "for the Havenwood. The elders of the wild-elves meet here to discuss "
    "the future of the Wood. A secluded area to the west seems to serve "
    "as a forum for discussion. The path leads back south into the main "
    "area of the Wood."
    );
  SetListen("The area to the west seems very quiet.");
  SetSmell("The aroma of the forest is calm and reassuring.");
  SetInventory( ([
    HWD_NPC "/elder" : 1,
    HWD_NPC "/teller" : 1,
   ]) );
  SetExits( ([
   "south" : HWD_ROOM + "/gelf8",
   "west"  : HWD_ROOM + "/office",
   ]) );
}
