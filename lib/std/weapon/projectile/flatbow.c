#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("flatbow");
  SetId( ({ "bow", "flatbow" }) );
  SetAdjectives( ({ "elm", "flat" }) );
  SetShort("an elm flatbow");
  SetLong(
    "A flatbow made from a solid piece of elm, narrowed at the arrow rest and "
    "tips."   
  );
    SetClass(6);
  SetDamagePoints(1500);
  SetValue(300);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetHands(2);
  SetMass(45);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
}

