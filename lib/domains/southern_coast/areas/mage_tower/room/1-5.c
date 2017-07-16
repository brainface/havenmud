#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetShort("a curve in the hallway");
  SetExits( ([
    "south" : TOWER_ROOM "1-4",
    "east"  : TOWER_ROOM "1-6",
    ]) );
  SetInventory( ([
    ]) );
  SetLong("The tower hallway continues to curve here, leading both "
          "east and south along the outer wall of the tower. "
          "To the south, the hallway seems to lead into some form "
          "of room, while to the east is the central stairwell of "
          "the tower. The floor here is made of slabs of stone which "
          "seem to fit together poorly.");
  SetItems( ([
    ({ "floor", "slab", "slabs", "stone" }) : "The floor is made up "
              "of slabs of stone which fit together poorly.",
    ]) );
  SetSmell( ([
    "default" : "The dust continues to float through the air here.",
    ]) );
  SetListen( ([
     "default" : "The tower is ominously silent.",
    ]) );
}
