#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("dagger");
  SetShort("a red bladed dagger");
  SetLong(
    "A finely crafted dagger with a blade "
    "made of a reddish metal."
  );
  SetId( ({"red bladed dagger", "red dagger" }) );
  SetClass(13);
  SetDamagePoints(2000);
  SetValue(400);
  SetMass(15);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(SLASH);
}

