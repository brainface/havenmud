#include <lib.h>
#include <climb.h>
#include "../defs.h"

inherit LIB_ITEM;
inherit LIB_CLIMB;
 
 
static void create() {
   ::create();
   SetShort("an intricate staircase");
   SetLong("This staircase looks to be crafted from wood "
           "and slightly aged ivory. It leads downward into "
		   "the tower.");
   SetId( ({"staircase"}) );
   SetClimb(
    TOWER_ROOMS "twer09", CLIMB_DOWN,
   );
   SetMaterials( ({"natural"}) );
   SetAdjectives( ({ "intricate","black" }) );
   SetKeyName("starcaise");
   SetPreventGet("The staircase prevents you.");
}