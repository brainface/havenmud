#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("rapier");
  SetId( ({ "rapier" }) );
  SetAdjectives( ({ "red", "bladed", "reddish", "metal" }) );
  SetShort("a red bladed rapier");
  SetLong(
    "A finely crafted rapier with a blade "
    "made of a reddish metal."
  );
  SetVendorType(VT_WEAPON);
  SetClass(13);
  SetValue(500);
  SetMass(60);
  SetDamagePoints(2000);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetMaterial("metal");
  SetRepairDifficulty(10);
}

