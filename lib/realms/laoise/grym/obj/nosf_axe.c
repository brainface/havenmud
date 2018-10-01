#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("axe");
  SetShort("a red bladed axe");
  SetLong(
    "A finely crafted axe with a blade "
    "made of a reddish metal."
  );
  SetId( ({"red bladed axe", "red axe"}) );
  SetClass(13);
  SetDamagePoints(2000);
  SetValue(450);
  SetMass(75);
  SetVendorType(VT_WEAPON);
  SetWeaponType("hack");
  SetDamageType(SLASH);
}

