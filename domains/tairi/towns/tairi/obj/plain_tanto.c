/*
  tanto for the ferry captain
*/
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("steel tanto");
  SetId( ({ "tanto" }) );
  SetAdjectives( ({ "steel" }) );
  SetShort("a steel tanto");
  SetLong("This tanto is a slim, short blade with a "
    "sharp point, mounted in a wooden hilt. It lacks "
    "the decoration of other such weapons found in "
    "Tairi, and nicks and scuffs mar the blade."
  );
  SetHands(1);
  SetClass(12);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(160);
  SetMass(200);
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(5);
 }

