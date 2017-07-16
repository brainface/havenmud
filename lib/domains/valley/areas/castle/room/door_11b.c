#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("east", ([ "id" : ({ "east door"}),
                       "short" : "the east door",
                       "long" : "The door provides an eastern exit, "
                          "and seems to be fairly sturdy and solid.",
                       "lockable" : 0
                  ]) );
   SetSide("west", ([ "id" : ({ "west door" }),
                       "short" : "the west door",
                       "long" : "The door provides a western exit, "
                          "and seems to be fairly sturdy and solid.",
                       "lockable" : 0
                  ]) );
   SetClosed(1);
}