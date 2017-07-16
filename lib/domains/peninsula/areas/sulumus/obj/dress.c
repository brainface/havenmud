// Proximo@Pax Imperialis
// 06/19/2003

#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dress");
  SetId( ({ "dress" }) );
  SetAdjectives( ({ "old", "green" }) );
  SetShort("an old green dress");
  SetLong(
     "This dress has the signs of and old, worn, and loved appearance. While there are "
     "noticable flaws and stains, it looks as though there was care to at least attempt to "
     "hide these flaws. The stitching looks to have begun to separate after many years of "
     "being held together. "
     );
  SetMass(120);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetWarmth(7);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  // SetProtection(PIERCE, 1);
  // SetProtection(BLUNT, 1);
  // SetProtection(SLASH, 1);
  SetSize(SIZE_MEDIUM);
}
