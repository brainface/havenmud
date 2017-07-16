#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("lance");
  SetShort("a red tipped lance");
  SetLong(
    "A finely crafted footman’s lance with a tip "
    "made of a reddish metal."
  );
  SetId( ({"red tipped axe", "red lance", "footman’s lance",
          "red footman’s lance" }) );
  SetClass(13);
  SetDamagePoints(2000);
  SetValue(450);
  SetMass(60);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
}

