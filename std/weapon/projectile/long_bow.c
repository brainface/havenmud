#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("long bow");
  SetId( ({ "bow" }) );
  SetAdjectives( ({ "long", "standard", "good", "wood", "wooden" }) );
  SetShort("a long bow");
  SetLong(
    "A standard long bow made of good wood and animal sinew."
  );
  SetClass(11);
  SetDamagePoints(1300);
  SetValue(300);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetHands(2);
  SetMass(45);
  SetMaterial( ({ "wood", "natural" }) );
  SetVendorType(VT_WEAPON);    
}
