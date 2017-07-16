#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("shotgun");
  SetId( ({ "shotgun", "boomstick" }) );
  SetAdjectives( ({ "12", "gauge" }) );
  SetShort("a 12 gauge BOOMSTICK");
  SetLong(
    "This is a Stoeger IGA 20 inch Coach side by side shotgun - 12 gauge. "
    "It is not a Remington. That's right this sweet baby was made in Grand "
    "Rapids, Michigan. Retails for about $109.95. It's got a walnut stock, "
    "cobalt blue steel, and a hair trigger. That's right, shop smart, shop "
    "S-mart."
  );
  SetClass(50);
  SetDamagePoints(5000);
  SetValue(500000000);
  SetWeaponType("projectile");
  SetDamageType(HEAT|PIERCE);
  SetMass(150);
  SetMaterial( ({ "metal", "wood" }) );
  SetVendorType(VT_WEAPON);
}
