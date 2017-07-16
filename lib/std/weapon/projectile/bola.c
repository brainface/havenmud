#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("bola");
  SetId( ({ "bola" }) );
  SetAdjectives( ({ "homemade", "twine", "rock" }) );
  SetShort("a homemade bola");
  SetLong(
    "This bola appears to have been homemade from "
    "twine and rock."
  );
  SetClass(7);
  SetDamagePoints(950);
  SetValue(80);
  SetWeaponType("projectile");
  SetDamageType(BLUNT);
  SetMass(50);
  SetMaterial( ({ "wood", "natural" }) );
  SetVendorType(VT_WEAPON);
}

