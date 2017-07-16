#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetShort("the center of the third floor");
  SetClimate("indoors");
  SetAmbientLight(35);
  SetExits( ([
    "south" : "3-1",
    ]) );
  SetLong("The tower reaches its summit here, with nothing above it. "
          "Off to the south, a hallway leads into the center of the "
          "tower. Torches line the walls, making this room fairly "
          "well lit. A large obsidian stairwell leads back into the "
          "bowels of the tower.");
  SetSmell( ([
    "default" : "The torches give off a scent of burning wood.",
    ]) );
  SetListen( ([
    "default" : "The torches crackle quietly.",
    ]) );
  SetItems( ([
    ({ "torch", "torches" }) : "The torches seem to be normal wooden "
                               "torches.",
    ]) );
  SetInventory( ([
    TOWER_OBJ "stair-3" : 1,
    ]) );
}
