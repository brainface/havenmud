// Proximo@Via Imperialis
// 05/30/2003

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
  SetKeyName("cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "a", "worn", "grey" }) );
  SetShort("a worn grey cloak");
  SetLong(
     "This large chunk of fabric is a old, worn, and abused cloak that has seen "
     "many rainstorms and many other harsh weatherly conditions. The fabric at "
     "one point might have been blue, as there are traces of blue dye still found "
     "within the greyish surface of the cloak. It is an old cloak, though it "
     "looks as it could still provide ample protection from the weather. "
  );
  SetMass(60);
  SetValue(15);
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  
  // SetProtection(PIERCE, 2);
  // SetProtection(BLUNT, 2);
  // SetProtection(SLASH, 2);
  SetWarmth(2);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_CLOAK);
  SetSize(SIZE_MEDIUM);
}
