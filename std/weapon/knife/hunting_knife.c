#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("hunting knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "hunting" }) );
  SetShort("a hunting knife");
  SetLong(
    "This weapon is carried by many hunters "
    "for skinning their captured game."
  );
  SetClass(8);
  SetDamagePoints(540);
  SetValue(120);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMass(25);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}

