// Proximo@Via Imperialis
// 05/30/2003

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
#include "../sulumus.h"

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather vest");
  SetId( ({ "vest" }) );
  SetAdjectives( ({ "boiled", "leather" }) );
  SetShort("a boiled leather vest");
  SetLong(
     "This piece of equipment was fashioned out of a fine leather hide. By "
     "stretching, folding, and curing the leather, this material was formed into "
     "a wearable piece of armour that can block an attack. By taking the curing "
     "process further and boiling the leather for a longer period of time, the "
     "armour has increased it's defensive capability, sacrificing looks and "
     "feel for stiffness and durability. "
  	 );
  SetMass(175);
  SetMaterial( ({ "leather" }) );
  SetRepairDifficulty(20);
  SetValue(250);
  SetWarmth(3);
  SetArmourClass(ARMOUR_LEATHER);
  // SetProtection(PIERCE, 18);
  // SetProtection(SLASH, 18);
  // SetProtection(BLUNT, 18);
  // SetProtection(COLD, 2);
  // SetProtection(HEAT, 2);
  // SetProtection(ACID, 2);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_VEST);
  SetSize(SIZE_MEDIUM);
}
