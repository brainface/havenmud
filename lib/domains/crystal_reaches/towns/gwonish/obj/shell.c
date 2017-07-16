#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("turtle shell");
  SetArmourType(A_BODY_ARMOUR);
  SetRestrictLimbs( ({ "torso", "right foreleg", "left foreleg",
                       "left rear leg", "right rear leg", }) );
  // SetProtection(BLUNT, 100);
  // SetProtection(SLASH, 100);
  SetWarmth(40);
  // SetProtection(PIERCE, 100);
  // SetProtection(HEAT, 100);
  SetArmourClass(ARMOUR_NATURAL);
  // SetProtection(COLD, 100);
  SetDamagePoints(8000);
  SetValue(300);
  SetMass(1200);
  SetSize(SIZE_VERY_LARGE);
  SetShort("a giant turtle shell");
  SetId( ({ "shell" }) );
  SetAdjectives( ({ "giant", "turtle" }) );
  SetRepairDifficulty(80);
  SetMaterial("natural");
}
 
