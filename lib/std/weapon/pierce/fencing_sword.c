#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("fencing sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "fencing" }) );
  SetShort("a fencing sword");
  SetLong(
    "A very thin, steel blade ends in a needle "
    "like point."
  );      
  SetClass(12);
  SetDamagePoints(500);
  SetValue(190);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMass(195);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}


