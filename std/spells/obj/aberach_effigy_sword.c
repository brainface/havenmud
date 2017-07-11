#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("flaming red two-handed sword");
  SetId( ({ "sword", }) );
  SetAdjectives( ({ "two", "handed", "twohanded", "flaming", "red" }) );
  SetShort("a flaming red two-handed sword");
  SetLong(
    "This evil looking weapon is an overly large two-handed sword that "
    "burns with an evil, unholy flame."
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(3500);
  SetValue(2000);
  SetClass(24);
  SetMass(180);
  SetMaterial( ({ "metal" }) );
  SetWeaponType("slash");
  SetDamageType(SLASH|HEAT);
  SetHands(2);
}
