#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("green bone breastplate");
  SetShort("a shiny green bone breastplate");
  SetId( ({ "breastplate" }) );
  SetAdjectives( ({ "bone", "green" }) );
  SetDamagePoints(20000);
  SetMaterial( ({  "natural" }) );
  SetRepairDifficulty(60);
  SetWarmth(10);
  SetValue(7000);
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(325);
  SetArmourType(A_ARMOUR);
  SetLong("This green breastplate is handcrafted from only the finest bones. "
          "It has almost a mirror-like reflection to it. It was obviously "
          "coated with some sort of liquid. The small carvings in the bones "
          "resemble many seen around the forest. ");
 SetProtectionBonus(COLD, 35);
 SetProtectionBonus(HEAT, 35);
 SetProtectionBonus(SLASH, 35);
 SetProtectionBonus(PIERCE, 35);
 SetProtectionBonus(BLUNT, 35);
 SetSize(SIZE_VERY_SMALL);
}
