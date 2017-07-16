#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("pocket knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "pocket", "small", "general-purpose" }) );
  SetShort("your grand-papy's pocket knife");
  SetLong(
    "A small, general-purpose pocket knife."
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(10);
  SetClass(50);
  SetValue(5);
  SetMass(25);
  SetMaterial( ({ "metal" }) );
  SetWeaponType("knife");
  SetDamageType(PIERCE);
}
