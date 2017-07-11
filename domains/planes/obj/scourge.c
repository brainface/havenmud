#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("wicked scourge");
  SetId( ({ "whip", "scourge" }) );
  SetAdjectives( ({ "wicked" }) );
  SetShort("a wicked scourge");
  SetLong(
    "A long multi-tailed whip with sharp blades threaded "
    "into the leather tails."
  );
  SetVendorType(VT_WEAPON);
    SetDamagePoints(3000);
  SetValue(200);
  SetClass(20);
  SetMass(100);
  SetMaterial( ({ "metal", "leather" }) );
  SetWeaponType("projectile");
  SetDamageType(SLASH);
}
