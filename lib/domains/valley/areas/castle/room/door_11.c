#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("north", ([ "id" : ({ "north door","door","tower door",
                                 "sturdy door","solid door",
                                 "strong door" }),
                       "short" : "the north door",
                       "long" : "The door provides a northern exit, "
                          "and seems to be fairly sturdy and solid.",
                       "lockable" : 0
                  ]) );
   SetSide("south", ([ "id" : ({ "south door","door","tower door",
                                 "sturdy door","solid door",
                                 "strong door" }),
                       "short" : "the south door",
                       "long" : "The door provides a southern exit, "
                          "and seems to be fairly sturdy and solid.",
                       "lockable" : 0
                  ]) );
   SetClosed(1);
}