#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  ::create();
  SetKeyName("sharp stiletto");
  SetId( ({  "stiletto" }) );
  SetAdjectives( ({ "sharp"  }) );
  SetShort("a sharp stiletto");
  SetLong(
    "This stiletto has a metal blade which is thin and triangular in shape. "
    "The hilt is composed of leather wrapped around the base numerous times "
    "and tucked inside itself for strength. The edges of the double sided "
    "blade are sharp and dangerous."
  );
  SetClass(14);
  SetDamagePoints(600);
  SetValue(200);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetMass(250);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(35);
}