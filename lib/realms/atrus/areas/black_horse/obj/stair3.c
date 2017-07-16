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
  SetLong("Wooden set of steps offer an descending route "
          "Perhaps you could climb down them?");
  SetClimb(BHI_ROOM + "2hallway1", CLIMB_DOWN);
}
