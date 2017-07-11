
#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include "../prisoncamp.h"
inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("boots");
  SetShort("a pair of spiked toe boots");
  SetId( ({ "boots" }) );
  SetAdjectives(  ({ "spiked", "spiked toe", "pair", "pair of" })  );
  SetLong(
    "These dark leather spiked toe boots are perfect for kicking "
    "elves to enforce discipline, or just for laughs."
  );
  SetMass(75);
  SetValue(50);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({ "leather"}) );
  SetWarmth(5);
  SetDamagePoints(500);
  // SetProtection(COLD, 2);
  // SetProtection(HEAT, 2);
  // SetProtection(SHOCK, 2);
  // SetProtection(WATER, 2);
  // SetProtection(ACID, 2);
  // SetProtection(BLUNT, 5);
  // SetProtection(SLASH, 5);
  // SetProtection(PIERCE, 5);
  SetArmourType(A_BOOT);
  SetProperty("multiples", 1);
  SetVendorType(VT_ARMOUR);
}
