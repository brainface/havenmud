//   Ewok reinforced armour   //

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cap");
  SetId( ({ "cap", "leather cap" }) );
  SetAdjectives( ({ "studded", "leather" }) );
  SetMaterials( ({ "leather" }) );
  SetRepairDifficulty(15);
  SetShort("a studded leather cap");
  SetLong("Small iron studs ring this leather cap along its most "
     "reinforced lines around the ears and neck. Though not the best "
     "protection, it offers slightly more that standard leather goods. ");
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_REINFORCED);
  SetSize(SIZE_SMALL);
  SetMass(40);
  SetWarmth(5);
  SetValue(75);
  SetDamagePoints(350);
  SetArmourType(A_HELMET);
}
