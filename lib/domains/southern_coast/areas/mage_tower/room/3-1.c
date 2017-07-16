#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetAmbientLight(35);
  SetShort("a hallway intersection");
  SetExits( ([
    "west" : "3-4",
    "north" : "3-6",
    "east" : "3-2",
    ]) );
  SetInventory( ([
    TOWER_NPC "app_mage" : 2,
    ]) );
  SetSmell( ([
    "default" : "The smell of burning wood taints the air.",
    ]) );
  SetListen( ([
    "default" : "A faint murmur echoes in the hallway.",
    ]) );
  SetLong("The hallway leads off in three directions from here. "
          "To the east and west, the hall seems to dead end into "
          "a wider room, while to the north the hallway leads back "
          "towards the obsidian stairwell. The floor on this level "
          "is tiled in marble, which reflects the torchlight with "
          "a quivering stillness.");
  SetItems( ([
    "floor" : "This is a marble tiled overlay.",
    ]) );
}
