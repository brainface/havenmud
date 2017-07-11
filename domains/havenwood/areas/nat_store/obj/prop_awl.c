#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("awl");
  SetShort("an iron awl");
  SetLong(
    "A glorified nail with a wooden grip, "
    "this tool is used to poke holes through "
    "thick leather."
  );
  SetId( ({"awl"}) );
  SetAdjectives( ({ "iron" }) );
  SetClass(12);
  SetDamagePoints(1200);
  SetValue(300);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMass(30);
  SetMaterial( ({ "wood","metal" }) );
  SetVendorType(VT_WEAPON);
}

