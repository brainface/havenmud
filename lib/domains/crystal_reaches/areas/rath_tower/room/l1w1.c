#include <lib.h>
#include "../rath.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("the library");
  SetExits( ([
    "east" : TOWER_R + "/entrance",
    ]) );
  SetAmbientLight(40);
  SetLong("This wing of the tower seems to be a library of some sort. "
         "Books line the shelves in a manner that shows care for the "
         "literary arts beyond the care the rest of the tower holds. "
         "There is an exit to the east.");
  SetItems( ([
    ({ "book", "books" }) : "The books expound on a number of subjects "
                            "from history to geography.",
    ({ "shelf", "shelves" }) : "The shelves appear well dusted and "
                               "well cared for.",
    ]) );
  SetSmell( ([
    "default" : "The peaceful smell of parchment and vellum fills the air.",
    ]) );
  SetListen( ([
    "default" : "Like all good libraries, this room is quiet.",
    ]) );
  SetInventory( ([
    TOWER_N + "/healer" : 1,
    ]) );
 }
