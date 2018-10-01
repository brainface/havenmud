#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("buckler");
  SetShort("a small buckler");
  SetId( ({ "shield", "buckler" }) );
  SetAdjectives( ({ "small" }) );
  SetLong(
     "This is a small wooden buckler with leather covering. A simple."
     "shield worn on the arm or hand to protect the recruits."
   );
  SetDamagePoints(450);
  SetValue(100);
  SetArmourType(A_SHIELD);
  SetMass(150);
  SetRepairDifficulty(10);
  SetRepairSkills( ([
    "wood working"    : 1,
    "leather working" : 1,
    "armour smithing" : 1,
    ]) );
  SetMaterial( ({"wood","leather" }) );
  SetArmourClass(ARMOUR_REINFORCED);
}
