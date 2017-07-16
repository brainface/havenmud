#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("kopesh sword");
  SetId( ({ "sword", "kopesh" }) );
  SetAdjectives( ({ "kopesh", "small", "curved" }) );
  SetShort("a small curved kopesh sword");
  SetLong(
    "This small sword has a deep curved blade that is thicker towards the "
    "point than it is at the hilt. It is called a \"kopesh sword\" by "
    "the tribes of the Yozrath Desert."
  );
  SetClass(10);
  SetDamagePoints(1800);
  SetValue(0);
  SetWeaponType("slash");
  SetDamageType(SLASH);  
  SetMass(175);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(5);
  SetVendorType(VT_WEAPON);
}


