#include "../mage_tower.h"
#include <lib.h>
inherit LIB_ROOM;

static void create() {
  
  ::create();
  SetProperty("no teleport", 1);
  SetClimate("indoors");
  SetShort("a curve in the hallway");
  SetExits( ([
    "south" : "1-2",
    "west"  : "1-6",
    ]) );
  SetSmell( ([
    "default" : "A pall of dust sits in the air.",
    ]) );
  SetListen( ([
    "default" : "Silence fills the air.",
    ]) );
  SetLong("The walls curve here, heading both south and west. "
          "To the south, the walls seem to curve back more, but "
          "to the west the hallway opens into some type of room. "
          "The floor is a polished stone which oddly seems to have "
          "very little dust lying on it.");
  SetItems( ([
    "floor" : "The floor is a smooth polished stone here.",
    "dust"  : "The dust seems to have not settled here.",
    ]) );
  SetInventory( ([
    ]) );
}
