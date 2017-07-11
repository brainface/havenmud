#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("south", ([ "id" : ({ "south door","chapel door","tidy door",
                                 "wooden door","door" }),
                       "short" : "a wooden door",
                       "long" : "This door leads into the building to "
                          "the south.  It is made of basic wood, and "
                          "has a generally tidy appearance to it.",
                       "lockable" : 0
                  ]) );
   SetSide("north", ([ "id" : ({ "north door","chapel door","tidy door",
                                 "wooden door","door" }),
                       "short" : "a wooden door",
                       "long" : "This door leads out of this building in "
                          "the northern direction.  It is made of basic "
                          "wood, and has a generally tidy appearance to "
                          "it.",
                       "lockable" : 0
                  ]) );
}