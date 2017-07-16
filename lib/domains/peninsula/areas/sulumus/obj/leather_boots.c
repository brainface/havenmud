// Proximo@Via Imperialis
// 05/30/2003

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include "../sulumus.h"

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather boots");
  SetId( ({ "boots" }) );
  SetAdjectives( ({ "boiled", "leather" }) );
  SetShort("a pair of boiled leather boots");
  SetLong(
     "These pieces of equipment were fashioned out of a fine leather hide. By "
     "stretching, folding, and curing the leather, this material was formed into "
     "a pair of wearable boots as a piece of armour that can block an attack. "
     "By taking the curing process further and boiling the leather for a "
     "longer period of time, the armour has increased it's defensive capability, "
     "sacrificing looks and feel or stiffness and durability. "
  );
  SetMass(80);
  SetMaterial( ({ "leather" }) );
  SetRepairDifficulty(10);
  SetValue(140);
  SetProperty("multiples", 1);
  SetArmourClass(ARMOUR_LEATHER);
  // SetProtection(PIERCE, 18);
  SetWarmth(3);
  // SetProtection(SLASH, 18);
  // SetProtection(BLUNT, 18);
  // SetProtection(HEAT, 2);
  // SetProtection(COLD, 2);
  // SetProtection(ACID, 2);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  SetSize(SIZE_MEDIUM);
}
