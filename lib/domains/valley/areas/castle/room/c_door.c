#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("south", ([
                       "id" : ({ "south door","door" }),
                       "short" : "the south door",
                       "long" : "The door fades into the background "
                                "as if it doesn't want to be noticed.  "
                                "It is south.",
                       "lockable" : 0,
                  ]) );
   SetSide("north", ([
                       "id" : ({ "north door","door" }),
                       "short" : "the north door",
                       "long" : "The door stands out in the stone "
                                "wall to the north.",
                       "lockable" : 0,
                  ]) );
}