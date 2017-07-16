#include <lib.h>
#include "../mage_tower.h"
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetShort("a curve in the hallway");
  SetClimate("indoors");
  SetExits( ([
    "south" : "2-2",
    "west"  : "2-6",
    ]) );
  SetSmell( ([
    "default" : "There are no unusual scents here.",
    ]) );
  SetListen( ([
    "default" : "The hallway is silent.",
    ]) );
  SetLong("The hallway curves south and west here, leading off "
          "into the tower.  To the south the hallway leads into "
          "a curve which heads to the far side of the tower, while "
          "to the west the hallway opens up into the center of "
          "the tower.");
  SetInventory( ([
    ]) );
}
