#include <lib.h>
#include "../path.h"
inherit LIB_ROOM;

static void create() {
  ::create();
  SetShort("a rolling hillside");
  SetExits( ([
    "south" : LLORYK "room/hb4",
    "north"  : LLORYK "room/farm4",
    "west"  : LLORYK "room/farm2",
    "east"  : LLORYK "room/uh5",
    ]) );
  SetLong("The rolling hillside of the the Shire is a fine place "
          "for farming of all varieties. Off to the south, the "
          "hillside is replaced by a long path which eventually "
          "leads out of the Shire, while to the east lies the "
          "main road leading through town.");
  SetSmell( ([
    "default" : "Fertilizer and sheep stinks up the air.",
    ]) );
  SetListen( ([
    "default" : "The occasional \"moo\" drifts in from afar.",
    ]) );
  SetTown("Wilderness");
  SetInventory( ([
    LLORYK "npc/sheep"  : 1,
    LLORYK "npc/farmer" : 1,
    ]) );
  SetItems( ([
    ]) );
  SetFarmingBonus(15);  
}
    
