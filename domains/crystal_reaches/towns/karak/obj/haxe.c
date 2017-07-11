// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../karak.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("axe");
  SetId( ({ "axe" }) );
  SetAdjectives( ({ "hand", "steel" }) );
  SetShort("a steel hand axe");
  SetLong(
    "This axe illustrates the excellent weapon-craft of the orcish smiths. "
    "Although each smith makes large numbers of these yearly, each is finely "
    "and durably made, with a sharp edge it will hold for many uses. "
    "Scrollwork is carved into the handle, which appears decorative "
    "but is, in fact, designed to improve the wielder's grip during battle."
  );
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(600);
  SetClass(13);
  SetValue(150);
  SetMass(100);
  SetMaterials( ({
    "metal",
  }) );
  SetRepairDifficulty(22);
}
