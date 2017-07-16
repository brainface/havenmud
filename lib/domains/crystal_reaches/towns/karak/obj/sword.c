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
  SetKeyName("iron broadsword");
  SetId( ({ "broadsword", "sword" }) );
  SetAdjectives( ({ "iron", "broad" }) );
  SetShort("an iron broadsword");
  SetLong(
    "This sword tapers from a long base to an angled point. It has "
    "a shallow groove running down the middle, which flares at the "
    "base to form spiked cross-guards to either side. Its handle is "
    "covered with wrapped black leather. The pommel circular and dimpled "
    "inwards on either side."
  );
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(575);
  SetClass(12);
  SetValue(100);
  SetMass(75);
  SetMaterials( ({
  	"metal"
  }) );
  SetRepairDifficulty(20);
}
