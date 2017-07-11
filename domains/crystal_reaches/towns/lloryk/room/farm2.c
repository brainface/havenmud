#include <lib.h>
#include "../path.h"
#include <std.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a small field");
  SetExits( ([
    "north" : LLORYK "room/farm3",
    "east"  : LLORYK "room/farm1",
    ]) );
  SetLong("The rolling hillside of the the Shire is a fine place "
          "for farming of all varieties. To the east leads back to "
          "town while to the north a large chicken coop can be seen "
          "in the distance.");
  SetTown("Wilderness");
  SetItems( ([
      ({ "coop" }) : 
         "The large chicken coop can be seen tot he north.",
   ]) );
  SetItemAdjectives( ([
      "coop" : ({ "chicken", "large" }),
   ]) );
  SetSmell( ([
    "default" : "Fertilizer and sheep stinks up the air.",
    ]) );
  SetListen( ([
    "default" : "The occasional \"moo\" drifts in from afar.",
    ]) );
  SetInventory( ([
    ]) );
  SetFarmingBonus(15);  
}
