#include <lib.h>
#include <climb.h>
#include "../path.h"

inherit LIB_ITEM;
inherit LIB_CLIMB;
 
 
static void create() {
  item::create();
  SetShort("a rocky path");
  SetLong("The rocky path leading west and down.");
  SetId( ({"path"}) );
  SetClimb(
    ICE_ROOM "rocks", CLIMB_DOWN
  );
  SetMaterials( ({"natural"}) );
  SetAdjectives( ({ "rocky" }) );
  SetKeyName("path");
  SetPreventGet("you can't pick that up!");
}
