#include <lib.h>
#include <climb.h>
#include "../mage_tower.h"
inherit LIB_ITEM;
inherit LIB_CLIMB;

static void create() {
  item::create();
  SetId( ({ "stairwell" }) );
  SetPreventGet("You cannot get a stairwell!");
  SetShort("a stairwell");
  SetLong("This huge obsidian stairwell leads from the first "
          "to the third floor of the tower.  Perhaps you could "
          "climb up or down them?");
  SetClimb(TOWER_ROOM + "3-6", CLIMB_UP);
  SetClimb(TOWER_ROOM + "1-6", CLIMB_DOWN);
}
