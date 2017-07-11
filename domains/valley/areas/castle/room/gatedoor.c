#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("north", ([ "id" : ({ "north gate","north portcullis",
                                "gate","portcullis","grating" }),
                      "short" : "a portcullis",
                      "long" : "Interlocking bars of metal form a "
                         "grating to keep people out of the castle "
                         "to the north.",
                      "lockable" : 0,
                 ]) );
   SetSide("south", ([ "id" : ({ "south gate","south portcullis",
                                "gate","portcullis","grating" }),
                      "short" : "a portcullis",
                      "long" : "Interlocking bars of metal form a "
                         "grating to keep people out of the castle.  "
                         "It can be easily opened from in here, "
                         "however.",
                      "lockable" : 0,
                 ]) );
   SetClosed(1);
}