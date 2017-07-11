#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("gauntlet");
  SetShort("a green bone gauntlet");
  SetId( ({ "gauntlet" }) );
  SetAdjectives( ({ "green","bone" }) );
  SetArmourType(A_GLOVE);
  SetSize(SIZE_VERY_SMALL);
  SetLong("The green gauntlet is handcrafted from only the finest bones. "
          "It has almost a mirror-like reflection to it. It was obviously "
          "coated with some sort of liquid. The small carvings in the bones "
          "resemble many seen around the forest. It appears to be part out a "
          "full outfit. ");
  SetValue(1000);
  SetMass(25);
  SetDamagePoints(10000);
  SetArmourClass(ARMOUR_NATURAL);
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(50);
  SetWarmth(0);
  SetVendorType(VT_ARMOUR);
  SetProtectionBonus(COLD, 35);
  SetProtectionBonus(HEAT, 35);
  SetProtectionBonus(SLASH, 35);
  SetProtectionBonus(PIERCE, 35);
  SetProtectionBonus(BLUNT, 35);
 }
