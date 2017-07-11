#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("pistol");
  SetId( ({ "pistol" }) );
  SetAdjectives( ({ "regulation", "marine" }) );
  SetShort("a regulation marine pistol");
  SetLong(
    "This pistol is of the type normally issued to new marines in the Imperial "
    "Marines. It is fairly standard in all ways."
  );
  SetClass(25);
  SetDamagePoints(1500);
  SetValue(150);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetMass(50);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
}

