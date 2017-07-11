#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("south", ([
                       "id" : ({ "south door","dingy battered door",
                                 "dingy door","battered door","door" }),
                       "short" : "the south door",
                       "long" : "The door to the south is battered "
                          "up and worn from frequent use by the "
                          "workers of the house.",
                       "lockable" : 0
                  ]) );
   SetSide("north", ([
                       "id" : ({ "north door","dingy battered door",
                                 "dingy door","battered door" }),
                       "short" : "the north door",
                       "long" : "The door to the north is battered "
                          "up and worn from frequent use by the "
                          "workers of the house, slave, servant, and "
                          "serf.",
                       "lockable" : 0
                 ]) );
   SetClosed(1);
}