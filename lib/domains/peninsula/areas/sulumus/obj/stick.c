// Proximo@Via Imperialis
// 06/02/2003

#include <lib.h>
#include "../sulumus.h"
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("stick");
  SetId( ({ "stick" }) );
  SetAdjectives( ({ "a", "broken" }) );
  SetShort("a broken stick");
  SetLong(
     "This stick was once whole but now is only a portion of it's former size. "
     "A large stress fracture runs down the grain of the stick, suggesting "
     "it's been struck against a hard surface many times. "
  	 );
  SetClass(3);
  SetMaterial( ({ "wood" }) );
  SetRepairDifficulty(99);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_TREASURE);
  SetMass(110);
  SetDamagePoints(425);
  SetValue(2);
}
