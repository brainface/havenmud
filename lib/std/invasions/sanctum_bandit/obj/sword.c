/* Sword for bandit invasion */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("longsword");
  SetShort("a longsword of steel");
  SetId( ({ "longsword", "sword", "longsword of steel", "sword of steel" }) );
  SetAdjectives( ({ "steel" }) );
  SetLong(
    "This is a hardened steel longsword."
  );
  SetDamagePoints(800);
  SetValue(50);
  SetMass(80);
  SetClass(12);
  SetDamageType(SLASH);
  SetWeaponType("slash");
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(10);
}
