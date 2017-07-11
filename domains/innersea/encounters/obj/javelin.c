// mahkefel 20101117
// javelin
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("javelin");
  SetId( ({"javelin"}) );
  SetAdjectives( ({ "flinthead","flint","head" }) );
  SetShort("a flinthead javelin");
  SetLong(
    "This long wooden javelin has a simple head "
    "of sharpened flint and is weighted for "
    "throwing."
  );
  SetClass(13);
  SetDamagePoints(2000);
  SetValue(150);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetMass(300);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}

