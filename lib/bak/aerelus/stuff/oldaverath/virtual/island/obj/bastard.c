#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("bastard sword");
  SetShort("an oversized bastard sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "oversized", "bastard" }) );
  SetLong("This sword, sometimes called a hand and a half sword, "
          "is a much larger and more powerful weapon than a "
          "smaller sword would be. ");
  SetDamagePoints(2000);
  SetClass(15);
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetHands(2);
  SetValue(400);
}
