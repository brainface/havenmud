// A wild elephant with enhanced HP
// Urien@Haven 11JUN2023

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../world.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("wild elephant");
  SetId( ({ "elephant" }) );
  SetAdjectives( ({ "wild" }) );
  SetRace("elephant");
  SetClass("animal");
  SetGender("male");
  SetLevel(random(5) + 60);
  SetShort("a wild elephant");
  SetLong("This rugged looking elephant has escaped sentient "
          "captivity and roams in the wild. Sand weathered "
          "skin covers his exposed body. Dual tusks stick "
          "out of his head which show age and damage on them "
          "from predators.");
  SetStat("durability", random(10) + 150, 1); //very tough NPC
  SetAction(2, ({
     "The wild elephant slowly flutters his ears.",
     "The wild elephant stomps on the ground as it grazes.",
     }) );
  SetMeleeDamageType(PIERCE);
}
