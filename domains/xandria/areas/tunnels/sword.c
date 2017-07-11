#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("folded-resin sword");
  SetId( ({ "sword", }) );
  SetAdjectives( ({ "folded", "resin" }) );
  SetShort("a folded resin sword");
  SetLong(
    "This sword seems to have a very keen edge. However, the weapon isn't made of any form of "
    "metal! It appears to be a very highly polished type of some laminate resin."
    );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1500);
  SetClass(18);
  SetValue(150);
  SetMass(60);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetMaterial( ({ "natural" }) );
}
