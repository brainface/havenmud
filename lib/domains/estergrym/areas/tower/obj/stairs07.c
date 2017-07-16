#include <lib.h>
#include <climb.h>
#include "../defs.h"

inherit LIB_ITEM;
inherit LIB_CLIMB;
 
 
static void create() {
   ::create();
   SetShort("an intricate staircase");
   SetLong("This staircase looks to be crafted from wood "
           "and slightly aged ivory. It leads upward and "
		   "downward into the tower.");
   SetId( ({"staircase"}) );
   SetClimb(
           TOWER_ROOMS "twer08", CLIMB_DOWN,
             );
   SetClimb(
           TOWER_ROOMS "twer10", CLIMB_UP,
		     );
   SetMaterials( ({"natural"}) );
   SetAdjectives( ({ "intricate","black" }) );
   SetKeyName("staircase");
   SetPreventGet("The staircase prevents you.");
}
