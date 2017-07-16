#include <lib.h>
#include "../rome.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetWarmth(50);
  SetShort("The Explorer's Tent");
  SetExits( ([
    "out" : ROME_ROOM "bazaar",
    ]) );
  SetLong("The blue fabric of the tent gives everything in this "
          "room a faintly azure tint. Scattered around the room "
          "are various tools of exploration such as matches and "
          "torches. Outside, the bazaar beckons fools with money.");
  SetInventory( ([
    ROME_NPC "explorer" : 1,
    ROME_NPC "controller" : 1,
    ]) );
  SetSmell( ([
    "default" : "The faint smell of lamp oil hangs in the air.",
    ]) );
  SetListen( ([
    "default" : "The sounds of haggling merchants come from the bazaar.",
    ]) );
}
