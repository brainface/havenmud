#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("north", ([
                        "id" : ({ "north door","grand door"}),
                       "short" : "a grand door",
                       "long" : "The door to the north is grand, "
                          "very beautiful in its color and texture.",
                       "lockable" : 0,
                 ]) );
   SetSide("south", ([
                      "id" : ({ "south door","grand door" }),
                      "short" : "a grand door",
                       "long" : "The door to the south is grand, "
                          "very beautiful in its color and texture.",
                       "lockable" : 0,
                 ]) );
   SetClosed(1);
}