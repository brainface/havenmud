#include <lib.h>
#include <daemons.h>
#include <armour_types.h>
#include <size.h>
#include "../wood.h"
inherit LIB_TOWNGUARD;

static void create() {
  ::create();
  SetKeyName("sapling");
  switch(random(3)) {
    case 0:
      SetShort("a lumbering oak sapling");
      SetAdjectives(({"oak","lumbering"}));
      break;
    case 1:
      SetShort("a lumbering willow sapling");
      SetAdjectives(({"lumbering","willow"}));
      break;
    case 2:
      SetShort("a lumbering fir sapling");
      SetAdjectives(({"lumbering","fir"}));
      break;
  }
  SetId( ({ "sapling" }) );
  SetLong(
    "This young tree lumbers along the ground by its convulsing roots, "
    "limbs waving along in a breeze that doesn't exist. Broken axe blades "
    "stick out in various places, apparently repurposed from woodcutters "
    "that didn't know any better. Foxfire lights form the semblance of eyes "
    "and jagged mouth behind an elegantly carved mask placed in the upper "
    "reaches of the tree."
    );
  SetRace("tree");

  // tree race doesn't support armouor.
  DestLimb("head");
  AddLimb("head", "trunk", 1, ({A_HELMET}));

  SetSize(SIZE_LARGE);
  
  SetClass("fighter");
  SetSkill("natural magic",1);
  SetSkill("evokation",1);
  SetLevel(30);
  SetMorality(0);
  SetLimit(8);
  SetTown("Havenwood");
  SetWander(20);
  SetInventory( ([
    HWD_OBJ "/sap_mask" : "wear mask",
    HWD_OBJ "/sap_axe" : 3,
  ]) );
  SetAction(5, ({
    "!emote creaks along ponderously.",
    "!emote sways in the wind.",
    "!emote digs into the ground with its roots.",
  }) );
  SetCombatAction(10, ({
    "!emote howls inhumanly.",
    "!emote shakes the ground as it charges!",
    "!cast tangle",
  }) );
  SetFirstCommands( ({"wield axes"}) );
}

