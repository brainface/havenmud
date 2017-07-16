#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("west", ([ "id" : ({ "gates of ditmar","gate of ditmar",
                                "gate","gates" }),
                      "short" : "the Gates of Ditmar",
                      "long" : "The Gates of Ditmar go from the north to "
                               "south side of the cave, effectively "
                               "preventing people from going around.  "
                               "They also stretch nearly to the ceiling "
                               "of the cave, preventing entrance that "
                               "way, as well.",
                      "lockable" : 1,
                      "keys" : ({ "ditmar_gate_key" }),
                 ]) );
   SetSide("east", ([ "id" : ({ "gates of ditmar","gate of ditmar",
                                "gate","gates" }),
                      "short" : "the Gates of Ditmar",
                      "long" : "The Gates of Ditmar go from the north to "
                               "south side of the cave, effectively "
                               "preventing people from going around.  "
                               "They also stretch nearly to the ceiling "
                               "of the cave, preventing entrance that "
                               "way, as well.",
                      "lockable" : 1,
                      "keys" : ({ "ditmar_gate_key" }),
                 ]) );
   SetClosed(1);
   SetLocked(1);
}