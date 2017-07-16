#include <lib.h>
#include <climb.h>
#include "../mage_tower.h"
inherit LIB_ITEM;
inherit LIB_CLIMB;

static void create() {
  item::create();
  SetId( ({ "stairwell" }) );
  SetAdjectives( ({ "obsidian" }) );
  SetShort("a stairwell");
  SetLong("This huge obsidian stairwell leads from the first "
          "to the second floor of the tower.  Perhaps you could "
          "climb up them?");
  SetClimb(TOWER_ROOM + "2-6", CLIMB_UP);
  SetPreventGet("You cannot get a stairwell.");
}
