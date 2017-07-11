// Island
// Aerelus

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../island.h"
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("knife");
  SetId( ({ "knife" }) );
  SetShort("a deadly-sharp knife");
  SetAdjectives( ({ "deadly-sharp", "deadly", "sharp" }) );
  SetLong(
    "This hilt of this stunning weapon is made from the toughest steel, "
    "plated with expensive gold. The blade is as extremely sharp, and "
    "looks like it could cause a lot of damage in the right hands. "
    "This weapon is both beautiful and deadly."
  );
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetClass(30);
  SetDamagePoints(3000);
  SetValue(1500);
  SetMass(30);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(35);
  SetVendorType(VT_WEAPON);
}