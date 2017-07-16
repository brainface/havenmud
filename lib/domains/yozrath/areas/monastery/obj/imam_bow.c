// Monastery
// Aerelus
// 06/05/2006

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("crossbow");
  SetId( ({ "crossbow" }) );
  SetShort("a long, sturdy crossbow");
  SetAdjectives( ({ "long", "sturdy", "wooden", "black" }) );
  SetLong(
    "This sturdy, long crossbow is made of solid wood. It is dyed black "
    "and seems powerful enough to cause major damage to anyone who gets "
    "in its path. A balance, the symbol of the Kylin faith, has been etched "
    "into the weapon just above the trigger."
  );
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetClass(20);
  SetDamagePoints(1500);
  SetValue(450);
  SetMass(30);
  SetMaterial("wood");
  SetRepairDifficulty(15);
  SetVendorType(VT_WEAPON);
}
/** Approved by Laoise at Sun May 21 17:03:35 2006. **/