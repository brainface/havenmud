#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetShort("a curve in the hallway");
  SetClimate("indoors");
  SetSmell( ([
    "default" : "A rancid odor of acidic decay tortures the air.",
    ]) );
  SetListen( ([
    "default" : "A slurping noise echoes off the walls.",
    ]) );
  SetInventory( ([
    TOWER_NPC "slime" : 1,
    ]) );
  SetLong("The hallway floors and walls seem to be covered with "
          "some kind of weird black ooze. The rotting stench of "
          "decay seems to waft directly from that ooze. To the "
          "north the hallway leads away following the outer walls, "
          "while to the east the hallway leads to the south side of "
          "the tower.");
  SetExits( ([
    "east"  : "2-1",
    "north" : "2-5",
    ]) );
}
