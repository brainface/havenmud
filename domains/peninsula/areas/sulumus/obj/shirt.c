// Proximo@Via Imperialis
// 06/01/2003

#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include "../sulumus.h"

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shirt");
  SetId( ({ "shirt" }) );
  SetAdjectives( ({ "a", "worn", "grey" }) );
  SetShort("a worn grey shirt");
  SetLong(
     "This shirt has an old, worn, and abused appearance. The fabric at "
     "one point might have been blue, as there are traces of blue dye still "
     "found within the greyish surface of the shirt. It is an old shirt, though "
     "it still looks as though it could provide ample protection from the "
     "weather. "
  	 );
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetValue(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetWarmth(8);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_SHIRT);
  // SetProtection(PIERCE, 1);
  // SetProtection(BLUNT, 1);
  // SetProtection(SLASH, 1);
  SetSize(SIZE_MEDIUM);
}
