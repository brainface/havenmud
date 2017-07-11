#include <lib.h>
inherit LIB_DOOR;
#include "../castle.h"
 
static void create() {
   door::create();
   SetSide("east", ([ "id" : ({ "east door","opulent door","door"}),
                      "short" : "the east door",
                      "long" : "The door to the east is fairly grand, "
                               "but not too much so as to be gaudy.",
                      "lockable" : 0,
                 ]) );
   SetSide("west", ([ "id" : ({ "west door","opulent door","door"}),
                      "short" : "the west door",
                      "long" : "The door to the west is fairly grand, "
                               "but not too much so as to be gaudy.",
                      "lockable" : 0,
                 ]) );
   SetClosed(1);
}