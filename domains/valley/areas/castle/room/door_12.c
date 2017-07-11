#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("down", ([
                      "id" : ({ "downward trapdoor","downward door",
                                "trapdoor"}),
                      "short" : "the trapdoor",
                      "long" : "The trapdoor covers a hole in the "
                         "ground, preventing people from falling into "
                         "it when the trapdoor is closed.  When it is "
                         "open, one could go down from here.  "
                         "However, it doesn't look like it will open.",
                      "lockable" : 1,
                 ]) );
   SetClosed(1);
   SetLocked(1);
}