// mahkefel 20101117
// pirate knife
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("rigging knife");
  SetId( ({"knife"}) );
  SetAdjectives( ({ "rigging" }) );
  SetShort("a rigging knife");
  SetLong(
    "The heavy serrated blade of this knife "
    "is ideal for cutting rope. Turned against a "
    "living opponent, it would undoubtedly "
    "cause grevious wounds."
  );
  SetClass(25);
  SetDamagePoints(2000);
  SetValue(2500);
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetMass(350);
  SetMaterial( ({ "metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}

