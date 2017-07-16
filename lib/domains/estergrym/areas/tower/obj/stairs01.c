#include <lib.h>
#include <climb.h>
#include "../defs.h"

inherit LIB_ITEM;
inherit LIB_CLIMB;
 
 
static void create() {
   item::create();
   SetShort("an intricate staircase");
   SetLong("This staircase looks to be crafted from wood "
           "and slightly aged ivory. It leads upward into "
		   "the tower.");
   SetId( ({"staircase"}) );
   SetClimb(
    TOWER_ROOMS "/twer04", CLIMB_UP,
   );
   SetMaterials( ({"natural"}) );
   SetAdjectives( ({ "intricate","black" }) );
   SetKeyName("staircase");
   SetPreventGet("The staircase prevents you.");
}
