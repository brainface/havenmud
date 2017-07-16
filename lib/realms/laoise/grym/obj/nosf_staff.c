#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("staff");
  SetShort("a metal shod staff");
  SetLong(
    "A finely crafted staff encased in a layer of a "
    "reddish metal."
  );
  SetId( ({"metal shod staff", "metal staff", "shod staff" }) );
  SetClass(13);
  SetDamagePoints(2000);
  SetValue(400);
  SetMass(70);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
}

