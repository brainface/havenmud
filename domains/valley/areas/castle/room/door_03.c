#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("east", ([ "id" : ({ "east door","nice door" }),
                      "short" : "a wooden door",
                      "long" : "The east door is wooden, but "
                         "kept in good repair and is rather nice.",
                      "lockable" : 0,
                 ]) );
   SetSide("west", ([ "id" : ({ "west door","door","nice door",
                                "wooden door" }),
                      "short" : "a wooden door",
                      "long" : "The west door is wooden, but "
                         "kept in good repair and is rather nice.",
                      "lockable" : 0,
                 ]) );
   SetClosed(1);
}