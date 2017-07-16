#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("aged shortsword");
  SetShort("an aged shortsword");
  SetId( ({ "shortsword", "sword" }) );
  SetAdjectives( ({ "aged" }) );
  SetLong("This is a very old shortsword of the type used hundreds of "
          "years ago by the centurions of Rath Khan's armies.");
  SetClass(12);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetDamagePoints(550);
  SetValue(150);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(15);
  SetVendorType(VT_WEAPON);
}
