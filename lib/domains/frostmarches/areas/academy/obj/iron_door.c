/*
Look, it's a big iron door.
Tree references the sapling in arcanith.
*/

#include <lib.h>
inherit LIB_DOOR;

static void create() {
  ::create();
  SetSide("cabin",
    ([ 
      "id" : "door", 
      "short": "an iron door",
      "long" : "The door is made of solid iron. On its surface is painted a "
               "large silver tree with many blue leaves.",
      "lockable" : 0,
    ])
  );
  SetSide("out",
    ([
     "id" : "door", 
     "short": "an iron door",
     "long" : "The heavy iron door would repel any invader, if only it had "
              "a lock.",
     "lockable" : 0,
    ]) 
  );
  SetClosed(1);
}

