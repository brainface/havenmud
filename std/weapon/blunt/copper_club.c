#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetShort("a copper studded club");
  SetLong(
    "Small, jagged pieces of copper "
    "protrude from the head of this "
    "crude but effective club"
  );
  SetId( ({"club", "studded club","copper studded"}) );
  SetAdjectives( ({ "copper","studded" }) );
  SetClass(15);
  SetDamagePoints(900);
  SetValue(350);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("club");
  SetMass(250);
  SetMaterial( ({ "metal", "wood" }) );
  SetVendorType(VT_WEAPON);
}

