/* newbie club */
#include <damage_types.h>
#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("thick club");
  SetShort("a thick wooden club");
  SetId( ({ "club" }) );
  SetAdjectives( ({ "thick", "wooden" }) );
  SetClass(10);
  SetValue(10);
  SetMaterial( ({ "wood" }) );
  SetRepairDifficulty(5);
  SetMass(80);
  SetLong("This thick wooden club shows wear from beatings.");
  SetDamagePoints(2000);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
}
