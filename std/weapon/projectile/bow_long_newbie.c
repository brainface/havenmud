#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("bow");
  SetId( ({ "bow" }) );
  SetAdjectives( ({ "long", "standard", "wood", "wooden" }) );
  SetShort("a long bow");
  SetLong(
    "Good wood and animal sinew makes this standard long bow."
  );
  SetClass(11);
  SetDamagePoints(1300);
  SetValue(0);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetKeyName("standard long bow");
  SetHands(2);
  SetMass(45);
  SetMaterial( ({ "wood", "natural" }) );
  SetVendorType(VT_WEAPON);
}
