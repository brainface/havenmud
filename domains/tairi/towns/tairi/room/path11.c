#include <lib.h>
#include <std.h>
#include <domains.h>
#include "../tairi.h"
inherit LIB_FISHING;

static void create() {
  ::create();
  SetShort("along the beach");
  SetExits( ([
    "south" : "path10",
    "north" : INNERSEA_VIRTUAL "ocean/150,-50",
    ]) );
  SetSmell( ([
    "default" : "The faint smell of dead fish wafts the air.",
    ]) );
  SetListen( ([
    "default" : "The peaceful lapping of waves on the short disturbs the chill air.",
    ]) );
  SetProperty("coastal", 1);
  SetLong("The town of Tairi lies further south, but here the Endless Sea makes "
          "an appearance by lapping gently up on the beach. Far to the south, the "
          "Tai mountain range rise above as a guardian over the town.");
  SetItems( ([
      ({ "range", "mountain", "mountains", "guardian" }) : 
    	   "The snow-capped peaks of the Tai mountain range rise into the sky.",
      ({ "beach" }) : 
    	   "The beach is fine and sandy.",
      ({ "town", "tairi" }) :
    	   "The town of Tairi lies south along the dirt path.",
      ({ "sea", "ocean", "water"}) :
    	   "The deep green water gently laps up on the beach.",
      ]) );
   SetItemAdjectives( ([
      "range" : ({ "mountain", "tai" }),
     	"town"  : ({ "tairi" }),
     	"sea"   : ({ "deep", "green", "endless"}),
     	]) );
   SetSpeed(5);
   SetFish( ([
      DIR_STD "fish/guppy" : 100,
      DIR_STD "fish/trout" : 10,
      DIR_STD "fish/boot" : 1,
   ]) );
   SetChance(25);
   SetMaxFishing(12);
   SetInventory( ([
    STD_OBJ "dock_sign" : 1,
     TAI_RI_NPC "shipseller" : 1,
     TAI_RI_OBJ "taigalley"  : 1,
     TAI_RI_NPC "sail_trainer": 1,
     TAI_RI_OBJ "ferry" : 1,
     TAI_RI_NPC "ferrycaptain" : 1,
     ]) );
}
