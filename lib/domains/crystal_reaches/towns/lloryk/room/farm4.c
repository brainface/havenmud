#include <lib.h>
#include "../path.h"
#include <std.h>
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a hilly pasture");
  SetExits( ([
    "south" : LLORYK "room/farm1",
    "west"  : LLORYK "room/farm3",
    ]) );
  SetLong("The hills around the Shire make excellent pasture lands. They "
          "are lush and green and seem to continue on forever. The hills continue "
          "to the south while to the west a large chicken coop can be seen.");
  SetItems( ([
      ({ "hills", "hills", "land" }) : 
         "These lush green hills would be perfect to graze cows or sheep.",
      ({ "coop" }) : 
         "The large chicken coop can be seen to the west.",
   ]) );
  SetItemAdjectives( ([
      "coop" : ({ "chicken", "large" }),
      "land" : ({ "pasture" }),
   ]) );
  SetEnters( ([
    "coop" : LLORYK "room/chickencoop",
    ]) );
  SetSmell( ([
    "default" : "Fertilizer and pig stinks up the air.",
    ]) );
  SetListen( ([
    "default" : "The occasional \"moo\" drifts in from afar.",
    ]) );
  SetInventory( ([
    STD_NPC "cow" : 3,
    LLORYK "npc/sheep" : 2,
    ]) );
  SetFarmingBonus(15);  
}
