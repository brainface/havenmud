#include <lib.h>
#include <climb.h>
#include "../dalnairn.h"

inherit LIB_ITEM;
inherit LIB_CLIMB;
 
 
static void create() {
  item::create();
  SetShort("a rocky path");
  SetLong(
    "The path winds down the mountain to a foothill. "
    "One could easily, 'climb down path' to reach the "
    "foothill."
  );
  SetId( ({"path"}) );
  SetClimb(
    DAL_ROOM "foothill", CLIMB_DOWN
  );
  SetMaterials( ({"natural"}) );
  SetAdjectives( ({ "rocky" }) );
  SetKeyName("path");
  SetPreventGet("You can't pick that up!");
}
