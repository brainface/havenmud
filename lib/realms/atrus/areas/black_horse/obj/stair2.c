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
  SetLong("Wooden steps offer an descending route to the lower hallway. "
          "A similar staircase climbs up into the attic. "
          "Perhaps you could climb up or down them?");
  SetClimb(BHI_ROOM + "hallway", CLIMB_DOWN);
  SetClimb(BHI_ROOM + "attic", CLIMB_UP);
}
