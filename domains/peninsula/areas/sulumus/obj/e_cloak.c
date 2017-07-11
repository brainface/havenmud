// Proximo@Via Imperialis
// 06/01/2003

#include <lib.h>
#include <std.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>
#include "../sulumus.h"

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "an", "elegant", "red" }) );
  SetShort("an elegant red cloak");
  SetLong(
     "Upon first glance of his piece of clothing, one can see the fine details "
     "and care that was taken into weaving this cloak. The edges have a ruffled "
     "and puffed look, while a yellow colored pattern is seen upon the center "
     "of the cloak, roughly resembling a person riding a horse while holding a "
     "spear in a thrusting position. This cloak is heavy, thick, and expensive "
     "in looks, though it is unlikely this cloak will offer much protection "
     "against anything other than the weather. "
  	 );
  SetMass(95);
  SetValue(100);
  SetArmourClass(ARMOUR_CLOTH);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  // SetProtection(PIERCE, 2);
  // SetProtection(BLUNT, 2);
  // SetProtection(SLASH, 3);
  SetWarmth(8);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_CLOAK);
  SetSize(SIZE_MEDIUM);
}
