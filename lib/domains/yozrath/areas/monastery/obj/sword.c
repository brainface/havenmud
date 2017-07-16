// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("longsword");
  SetId( ({ "longsword", "sword" }) );
  SetShort("a sharp longsword");
  SetAdjectives( ({ "sharp","steel" }) );
  SetLong(
    "This longsword is made from some of the finest steel. It is very "
    "strong and has been sharpened with expert precision. It would make a "
    "deadly weapon in the hands of someone who knows how to use it. Engraved "
    "on the blade, near the hilt, is the symbol of the Kylin faith."
  );
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(17);
  SetDamagePoints(1500);
  SetValue(150);
  SetMass(100);
  SetMaterial("metal");
  SetRepairDifficulty(10);
  SetVendorType(VT_WEAPON);
}

/** Approved by Laoise at Sun May 21 17:03:27 2006. **/