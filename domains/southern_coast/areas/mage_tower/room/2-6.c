#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetShort("a wide open hallway");
  SetExits( ([
    "east" : "2-3",
    "west" : "2-5",
    ]) );
  SetInventory( ([
    TOWER_OBJ "stair-2" : 1,
    ]) );
  SetLong("The hallway continues east and west here with no discernable "
          "differences in either direction. There is a large obsidian "
          "stairwell leading both up and down firmly centered in the "
          "room. Off to the east, there appears to be a hallway "
          "which leads around the outer edge of the tower, while to "
          "the west the hallway seems to curve back into the center "
          "of the tower.");
  SetListen( ([
    "default" : "An occasional sound echoes lightly through the tower.",
    ]) );
  SetSmell( ([
    "default" : "The scent of old death wafts lightly into the stairwell.",
    ]) );
}
