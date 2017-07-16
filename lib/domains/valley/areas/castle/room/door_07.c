#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("up",   ([
                      "id" : ({ "upward trapdoor","upward door",
                                "trapdoor","door" }),
                      "short" : "the trapdoor",
                      "long" : "The trapdoor covers a hole in the "
                         "ground, preventing people from falling into "
                         "it from the other side when the trapdoor is "
                         "closed.  When it is open, one can go up "
                         "from here.",
                      "lockable" : 0,
                 ]) );
   SetSide("down", ([
                      "id" : ({ "downward trapdoor","downward door",
                                "trapdoor"}),
                      "short" : "the trapdoor",
                      "long" : "The trapdoor covers a hole in the "
                         "ground, preventing people from falling into "
                         "it when the trapdoor is closed.  When it is "
                         "open, one can go down from here.  Maybe "
                         "trying <open trapdoor> would get it open for "
                         "you, if you're having trouble.",
                      "lockable" : 0,
                 ]) );
   SetClosed(1);
}