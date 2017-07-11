#include <lib.h>
inherit LIB_DOOR;

static void create() {
   ::create();
   SetSide("out", ([ "id" : ({ "white door","door","door out",
                               "east door" }),
                     "short" : "the east door",
                     "long" : "The door to the east is plain, and "
                              "white just like the rest of the room.",
                     "lockable" : 0,
                ]) );
   SetSide("hospital", ([ "id" : ({ "white door","door","door in",
                                    "hospital door","west door" }),
                          "short" : "the west door",
                          "long" : "The door is plain and white, with "
                                   "hints of dirt on it.",
                          "lockable" : 0,
                   ]) );
   SetClosed(1);
}
