// Proximo@Pax Imperialis

// 07/14/2003

// Basic robe

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
  SetKeyName("robe");
  SetId( ({ "robe" }) );
  SetAdjectives( ({ "long", "brown" }) );
  SetShort("a long brown robe");
  SetLong(
     "Large folds of cloth woven together form this thick robe. The color of the "
     "robe looks to have been dyed with a brown ink. This robe is humble but "
     "comfortable, very suitable for traveling. "
     );
  SetMass(110);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetValue(35);
  // SetProtection(PIERCE, 1);
  // SetProtection(BLUNT, 1);
  // SetProtection(SLASH, 1);
  SetWarmth(8);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  SetSize(SIZE_MEDIUM);
}
