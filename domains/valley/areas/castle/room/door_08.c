#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("north", ([
                       "id" : ({ "north door","large door","door" }),
                       "short" : "the north door",
                       "long" : "The door to the north is very large.",
                       "lockable" : 0
                  ]) );
   SetSide("south", ([
                       "id" : ({ "south door","large door","door" }),
                       "short" : "the south door",
                       "long" : "The door to the south is very large.",
                       "lockable" : 0
                  ]) );
   SetClosed(1);
}