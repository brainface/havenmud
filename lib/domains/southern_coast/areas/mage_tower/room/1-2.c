#include "../mage_tower.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetShort("a hallway in the tower");
  SetClimate("indoors");
  SetExits( ([
    "west"  : "1-1",
    "north" : "1-3",
  ]) );
  SetSmell( ([
    "default" : "The smell of stirred up dust hangs in the air.",
  ]) );
  SetListen( ([
    "default" : "Silence echoes across the tower.",
  ]) );
  SetLong("The tower curves here along this hallway.  Leading north, "
          "the tower seems to curve in on itself, while to the west "
          "the hallway leads back towards the doors leading to the "
          "grove. Stone walls sit without a hint of moisture to "
          "betray their timeless passage through the ages.");
  SetItems( ([
    ({ "wall", "walls" }) : "The walls are dry and covered in light "
                            "dust.",
    ({ "dust" }) : "The dust is a pervasive fact of the tower.",
    ]) );
  SetInventory( ([
    TOWER_NPC + "spectre" : 1,
    ]) );
}
