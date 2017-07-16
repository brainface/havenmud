#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("halberd");
  SetId( ({ "halberd", "axe" }) );
  SetAdjectives( ({ "small", "gleaming" }) );
  SetShort("a small halberd");
  SetLong(
    "A gleaming axe head is mounted on a 4 foot "
    "haft."
  );
  SetClass(13);
  SetDamagePoints(1050);
  SetValue(200);
  SetWeaponType("pole");
  SetDamageType(SLASH);
  SetMass(300);
  SetMaterial( ({ "wood", "metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(2);
}

