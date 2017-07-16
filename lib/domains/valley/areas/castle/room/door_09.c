#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("north", ([ 
                       "id" : ({ "north door","small door","small entrance",
                                 "door","entrance" }),
                       "short" : "the north door",
                       "long" : "The door to the north is compact, "
                          "taking up little space and not seeming to be "
                          "of grand importance.",
                       "lockable" : 0
                  ]) );
   SetSide("south", ([ 
                       "id" : ({ "south door","small door","small entrance",
                                 "door","entrance" }),
                       "short" : "the south door",
                       "long" : "The door to the south is compact, "
                          "taking up little space and not seeming to be "
                          "of grand importance.",
                       "lockable" : 0
                  ]) );
   SetClosed(1);
}