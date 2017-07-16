// Proximo@Via Imperialis
// 06/02/2003

#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "a", "pair", "of", "simple", "small" }) );
  SetShort("a pair of simple small pants");
  SetLong(
     "This pair of pants looks to have been fashioned by someone who lacks "
     "any real talent. The stitching is uneven, the waistline not straight, "
     "and the colors are washed out and faded. This pair of pants was made "
     "for a child or small person of less than obvious wealth. "
     );
  SetMass(60);
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetValue(2);
  SetWarmth(7);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_PANTS);
  // SetProtection(PIERCE, 1);
  // SetProtection(BLUNT, 1);
  // SetProtection(SLASH, 1);
  SetSize(SIZE_SMALL);
}
