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
  SetKeyName("dress");
  SetId( ({ "dress" }) );
  SetAdjectives( ({ "a", "simple", "small" }) );
  SetShort("a simple small dress");
  SetLong(
     "This little dress looks to have been fashioned from someone who "
     "lacks any real talent. The stitching is uneven, the patterns less than "
     "perfect, and the colors are dull and drab. This dress was made for a "
     "child or small person of less than obvious wealth. "
  	 );
  SetMass(70);
  SetValue(2);
  SetArmourClass(ARMOUR_CLOTH);
  SetWarmth(7);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  // SetProtection(PIERCE, 1);
  // SetProtection(BLUNT, 1);
  // SetProtection(SLASH, 1);
  SetSize(SIZE_SMALL);
}
