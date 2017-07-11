#include <lib.h>
inherit LIB_DOOR;

static void create() {
   door::create();
   SetSide("up", ([
                    "short" : "the door above",
                    "id" : ({ "door","door above" }),
                    "long" : "The door is plain and wooden. "
                             "It has a large lock on it.",
                    "lockable" : 0,
              ]) );
   SetLocked(1);
   SetClosed(1);
}