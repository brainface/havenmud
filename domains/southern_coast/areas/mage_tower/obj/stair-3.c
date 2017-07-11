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
  SetLong("This huge obsidian stairwell leads from the third "
          "to the second floor of the tower.  Perhaps you could "
          "climb down them?");
  SetClimb(TOWER_ROOM + "2-6", CLIMB_DOWN);
}
