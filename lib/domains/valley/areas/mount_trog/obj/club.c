/* A club for the ghoul */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("large club");
  SetShort("a large club");
  SetId( ({ "club" }) );
  SetAdjectives( ({ "large" }) );
  SetClass(10);
  SetDamagePoints(500);
  SetMaterial( ({ "wood" }) );
  SetRepairDifficulty(5);
  SetValue(50);
  SetMass(80);
  SetDamageType(BLUNT);
  SetWeaponType("blunt");
  SetVendorType(VT_WEAPON);
  SetLong("This large club looks menacing and quite heavy.");
 }
