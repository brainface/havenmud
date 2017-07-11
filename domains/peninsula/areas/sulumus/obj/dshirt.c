// Proximo@Pax Imperialis
// 06/19/2003

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include "../sulumus.h"

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shirt");
  SetId( ({ "shirt" }) );
  SetAdjectives( ({ "a", "dusty", "white" }) );
  SetShort("a dusty white shirt");
  SetLong(
     "This shirt was once very clean and had an unmistakable white appearance. Now, "
     "as the shirt is covered in dust and soot, it has lost much of its "
     "original color and texture. "
  );
  SetMass(65);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetValue(5);
  SetArmourClass(ARMOUR_CLOTH);
  SetWarmth(4);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_SHIRT);
  // SetProtection(PIERCE, 1);
  // SetProtection(BLUNT, 1);
  // SetProtection(SLASH, 1);
  SetSize(SIZE_MEDIUM);
}
