// Proximo@Via Imperialis
// 06/01/2003

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include "../sulumus.h"

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "a", "pair", "of", "worn", "grey" }) );
  SetShort("a pair of worn grey pants");
  SetLong(
     "This pair of pants has an old, worn, and abused appearance. The fabric at "
     "one point might have been blue, as there are traces of blue dye still "
     "found within the greyish surface of the pants. It is an old pair, though "
     "it still looks as though it could provide ample protection from the weather. "
     );
  SetMass(70);
  SetValue(15);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetWarmth(8);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_PANTS);
  // SetProtection(PIERCE, 1);
  // SetProtection(BLUNT, 1);
  // SetProtection(SLASH, 1);
  SetSize(SIZE_MEDIUM);
}
