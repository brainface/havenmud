//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
//

#include <lib.h>
#include <climb.h>
#include "../dalnairn.h"

inherit LIB_ITEM;
inherit LIB_CLIMB;
 
 
static void create() {
  ::create();
  SetShort("a wooden staircase");
  SetLong(
    "This wooden staircase comes equipped with hand railings. "
  );
  SetId( ({
    "staircase", "stairs"
  }) );
  SetClimb(
    DAL_BLD "rest_02", CLIMB_DOWN
  );
  SetMaterials( ({"wood"}) );
  SetAdjectives( ({ 
    "wood", "wooden" 
  }) );
  SetKeyName("staircase");
  SetPreventGet("The staircase doesn't budge!");
}
