#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("red sword");
  SetId( ({ "longsword", "sword" }) );
  SetAdjectives( ({ "red", "bladed", "reddish", "long" }) );
  SetShort("a red bladed longsword");
  SetMaterials( ({ "metal" }) );
  SetLong(
    "A finely crafted longsword with a blade "
    "made of a reddish metal."
  );
  SetVendorType(VT_WEAPON);
  SetValue(500);
  SetMass(60);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(13);
  SetDamagePoints(2000);
  SetRepairDifficulty(10);
}

