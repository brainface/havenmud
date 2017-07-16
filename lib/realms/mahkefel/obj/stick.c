#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("stick");
  SetId( ({ "stick"}) );
  SetAdjectives( ({ "poking", }) );
  SetShort("a poking stick");
  SetLong(
    "This is a thin deadfall branch about halfling high in length. The end "
    "has been carved into a somewhat sharp point to provide maximum annoyance. "
  );
  SetClass(5);
  SetDamagePoints(100);
  SetHands(1);
  SetValue(50);
  SetWeaponType("pole");
  SetDamageType(PIERCE);
  SetMass(175);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
}

