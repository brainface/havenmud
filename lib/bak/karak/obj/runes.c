#include <lib.h>
#include "../karak.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetId( ({ "sword" }) );
  SetShort("a rune encrusted sword");
  SetLong("A faintly glowing sword etched with mystical runes "
          "of battle.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1500);
  SetClass(18);
  SetMaterial("metal");
  SetValue(2500);
  SetMass(200);
  SetWeaponType("slash");
  SetDamageType(SLASH);


}
