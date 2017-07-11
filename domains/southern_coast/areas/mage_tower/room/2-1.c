#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetShort("a passage in the tower");
  SetExits( ([
    "west" : "2-4",
    "east" : "2-2",
    ]) );
  SetSmell( ([
    "default" : "A rancid odor comes from the west.",
    ]) );
  SetListen( ([
    "default" : "A gurgling noise comes from the west.",
    ]) );
  SetLong("The hallway continues on to the east and west. "
          "To the west the hallway seems to curve around "
          "the edge of the tower into some kind of slimy "
          "spill, while to the east the tower curves back "
          "towards the center of the tower.");
  SetInventory( ([
    ]) );
}
