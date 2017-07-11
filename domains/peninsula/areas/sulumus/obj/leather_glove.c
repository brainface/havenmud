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
  SetKeyName("leather glove");
  SetId( ({ "glove" }) );
  SetAdjectives( ({ "boiled", "leather" }) );
  SetShort("a boiled leather glove");
  SetLong(
     "This piece of equipment was fashioned out of a fine leather hide. By "
     "stretching, folding, and curing the leather, this material was formed into "
     "a wearable glove as a piece of armour that can block an attack. "
     "By taking the curing process further and boiling the leather for a "
     "longer period of time, the armour has increased it's defensive capability, "
     "sacrificing looks and feel for stiffness and durability. "
     );
  SetMass(15);
  SetValue(120);
  SetMaterial( ({ "leather" }) );
  SetRepairDifficulty(10);
  SetArmourClass(ARMOUR_LEATHER);
  SetWarmth(1);
  // SetProtection(PIERCE, 18);
  // SetProtection(SLASH, 18);
  // SetProtection(BLUNT, 18);
  // SetProtection(HEAT, 2);
  // SetProtection(COLD, 2);
  // SetProtection(ACID, 2);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_GLOVE);
  SetSize(SIZE_MEDIUM);
}
