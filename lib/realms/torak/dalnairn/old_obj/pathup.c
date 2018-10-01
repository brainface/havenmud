#include <lib.h>
#include <climb.h>
#include "../dalnairn.h"

inherit LIB_ITEM;
inherit LIB_CLIMB;
 
 
static void create() {
  item::create();
  SetShort("a rocky path");
  SetLong(
    "The path winds up the foothill to an entrance "
    "in the mountain. One could easily, 'climb up "
    "path' to reach the mountain."
  );
  SetId( ({"path"}) );
  SetClimb(
    DAL_ROOM "entrance", CLIMB_UP
  );
  SetMaterials( ({"natural"}) );
  SetAdjectives( ({ "rocky" }) );
  SetKeyName("path");
  SetPreventGet("You can't pick that up!");
}
