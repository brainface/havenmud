// Proximo@Via Imperialis
// 06/02/2003

#include <lib.h>
#include "../sulumus.h"
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("rock");
  SetId( ({ "rock" }) );
  SetAdjectives( ({ "a", "piece", "of" }) );
  SetShort("a piece of rock");
  SetLong(
     "This small chunk of earth is nothing more than a simple rock. The "
     "surface is a jagged and sharp with small traces of crystal within "
     "it. "
     );
  SetClass(5);
  SetWeaponType("blunt");
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(99);
  SetDamageType(BLUNT);
  SetVendorType(VT_TREASURE);
  SetMass(200);
  SetDamagePoints(660);
  SetValue(3);
}
