#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("black bone breastplate");
  SetShort("a black bone breastplate");
  SetId( ({ "breastplate" }) );
  SetAdjectives( ({ "bone", "black" }) );
  SetDamagePoints(10000);
  SetMaterial( ({  "natural" }) );
  SetRepairDifficulty(50);
  SetWarmth(10);
  SetValue(4000);
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(300);
  SetArmourType(A_ARMOUR);
  SetLong("This black breastplate is handcrafted from only the finest bones. "
          "It has been coated with a clear substance that raised the durability "
          "of the armour greatly. The small carvings in the bones appear to show "
          "images of great triumph. ");
  // SetProtection(BLUNT, 10);
  // SetProtection(PIERCE, 10);
  // SetProtection(SLASH, 10);
  // SetProtection(HEAT, 10);
  // SetProtection(COLD, 10);
  SetSize(SIZE_VERY_SMALL);
}
