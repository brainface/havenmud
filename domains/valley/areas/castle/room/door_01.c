#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("east", ([ "id" : ({ "east door","non-descript door",
                                "small door","door","wooden door",
                                "plain door" }),
                      "short" : "the east door",
                      "long" : "The door is made of a strong wood, "
                         "fairly small and sturdy.",
                      "lockable" : 0
                 ]) );
   SetSide("west", ([ "id" : ({ "west door","non-descript door",
                                "small door","door","wooden door",
                                "plain door" }),
                      "short" : "the west door",
                      "long" : "The door is made of a strong wood, "
                         "fairly small and sturdy.",
                      "lockable" : 0
                 ]) );
   SetClosed(1);
}