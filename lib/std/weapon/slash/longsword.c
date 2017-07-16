#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("longsword");
  SetId( ({ "sword", "longsword" }) );
  SetAdjectives( ({ "steel", "long" }) );
  SetShort("a steel longsword");
  SetLong(
    "The finely crafted steel blade of this "
    "sword gleams in the light."
  );
  SetClass(14);
  SetDamagePoints(1800);
  SetValue(360);
  SetWeaponType("slash");
  SetDamageType(SLASH);  
  SetMass(175);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}


