#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("khopesh sword");
  SetId( ({ "sword", "khopesh" }) );
  SetAdjectives( ({ "khopesh", "scythe", "like" }) );
  SetShort("a scythe-like khopesh sword");
  SetLong(
    "This large sword has a hook that makes it look similiar to the end of a scythe. "
    "It is called a \"xandrian khopesh sword\" to distinguish it from the Yozrath variety."
  );
  SetClass(18);
  SetDamagePoints(2200);
  SetValue(560);
  SetWeaponType("slash");
  SetDamageType(SLASH);  
  SetMass(175);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}


