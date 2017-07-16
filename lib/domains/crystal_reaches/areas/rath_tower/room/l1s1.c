#include <lib.h>
#include "../rath.h"
inherit LIB_ROOM;

static void create() {
  room::create();
  SetClimate("indoors");
  SetShort("the grand hall");
  SetExits( ([
    "north" : TOWER_R + "/entrance",
    ]) );
  SetAmbientLight(40);
  SetLong("This chamber is huge. By any standards, it is oversized. "
          "The grand hall was obviously meant as a vantage point for "
          "the sitting ruler to command his forces with panache. To "
          "the north is the main entrance to the tower. The walls "
          "vault up into towering heights, obviously extending well "
          "beyond simply the first floor, while the floor centers on "
          "a dias which is elevated above the rest of the floor.");
  SetItems( ([
    "dias" : "The dias is an elevated chair for a ruler to sit upon.",
    ({ "wall", "walls" }) : "The walls are designed to appear much more "
                            "towering than they actually are.",
    ]) );
  SetSmell( ([
    "default" : "The room smells dank, like a mold or fungus has lived here.",
    ]) );
  SetListen( ([
    "default" : "A faint sound of dripping water echoes lightly in the room.",
    ]) );
  SetInventory( ([
    TOWER_N "/slime" : 1,
    ]) );
}
