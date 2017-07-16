#include <lib.h>
#include <climb.h>
#include "../bhi.h"
inherit LIB_ITEM;
inherit LIB_CLIMB;

static void create() {
  item::create();
  SetId( ({ "staircase" }) );
  SetPreventGet("You cannot get a staircase!");
  SetShort("a staircase");
  SetLong("Wooden steps offer an ascending route, while "
          "iron rung style steps proceed down into the " 
          "cellar. Perhaps you could "
          "climb up or down them?");
  SetClimb(BHI_ROOM + "2hallway1", CLIMB_UP);
  SetClimb(BHI_ROOM + "cellar", CLIMB_DOWN);
}
