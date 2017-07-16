// mahkefel 2011
// lisht knife
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("dagger");
  SetId( ({ "dagger" }) );
  SetAdjectives( ({ "curved" }) );
  SetShort("a curved dagger");
  SetLong(
    "The wide, curved blade of this bronze dagger is sharpened "
    "to a razor's edge. The bone hilt provided a decent grip "
    "for stabbing into something's unwilling innards."
  );
  SetMass(15);
  SetValue(100);
  SetClass(17);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetDamagePoints(1000);
  SetMaterial( ({ "metal" }) );
}

