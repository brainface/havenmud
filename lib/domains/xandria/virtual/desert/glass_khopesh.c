/*
// glass sword for elementals of xandrian desert.
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("glass khopesh");
  SetId( ({ "khopesh" }) );
  SetAdjectives( ({ "glass" }) );
  SetShort("a glass khopesh");
  SetLong(
    "This long sword has a wicked, sickle-shaped curve in the blade. Oddly, "
    "the whole of the blade is formed of polished glass and not metal. Small "
    "imperfections in the glass give the blade a prismatic color. Though "
    "dreadfully sharp, it doesn't look like it would withstand much "
    "punishment."
  );
  SetClass(20);
  SetDamagePoints(1000);
  SetValue(1000);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMass(100);
  SetMaterial( ({ "natural" }) );
  SetProperty("history",
    "This weapon was created by a creature of the Xandrian desert."
  );
  SetRepairDifficulty(25);
  SetVendorType(VT_WEAPON);
}

