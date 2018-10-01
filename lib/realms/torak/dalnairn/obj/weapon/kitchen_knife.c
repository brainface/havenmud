//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
//

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetShort("a kitchen knife");
  SetLong(
    "This knife looks like it would be better "
    "at carving apples rather then monsters. "
    "It has a heavy black handle and a sharp blade."
  );
  SetId( ({ "knife" }) );
  SetClass(7);
  SetDamagePoints(700);
  SetValue(100);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetKeyName("knife");
  SetMass(12);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetAdjectives( ({ 
    "kitchen" 
  }) );
}
