// A stray rock flea with a custom corpse
// Also custom body
// Urien@Haven 6JUN2023

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../world.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetKeyName("flea");
  SetId( ({ "flea" }) );
  SetAdjectives( ({ "rock" }) );
  SetLevel(random(8) + 2);
  SetRace("rock flea", 1);
  SetClass("insect");
  SetGender("female");
  SetShort("a rock flea");
  SetLong("Appearing very similar to any natural rock in Kailie, "
          "it is easy to overlook how well this flea is camoflaged. Small "
          "beady black eyes protrude from the rock carapace under "
          "the dual notch antenna. It is full grown, roughly the size "
          "of a plump squash during harvest. Normally two back legs "
          "support the agility of the pest while the other four "
          "sit motionless like stumps of a stool supporting the main "
          "mass. It is known to feed on decomposing leaves and "
          "particles of dust itself constantly feeding. The rock skin "
          "tone of the flea matches the environment near perfectly.");
  AddLimb("left back leg","torso",3, ({ }) );
  AddLimb("right back leg","torso",3, ({ }) );
  AddLimb("right antenna","head",2, ({ }) );
  AddLimb("left antenna","head",2, ({ }) );
  SetMeleeDamageType(ACID);
  SetMeleeAttackString("bite");
  SetAction(8, ({
     "The rock flea crouches in a very low position.",
     "The rock flea jumps quickly to a new location.",
     "The flea sits idle for a brief moment, motionless.",
     "The rock moves as it chews on something."  
     }) );
}
