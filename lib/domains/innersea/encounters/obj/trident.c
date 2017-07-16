// mahkefel 20101117
// MONKEY'S FIST!
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("trident");
  SetId( ({"trident"}) );
  SetAdjectives( ({ "bronze" }) );
  SetShort("a bronze trident");
  SetLong(
    "This weapon is made of old, tarnished "
    "bronze attached to the head of a wooden "
    "shaft. The tines look fairly sharp though, "
    "and the wicked barbs would no doubt feel "
    "unpleasant at best."
  );
  SetClass(25);
  SetDamagePoints(2000);
  SetValue(2500);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetMass(300);
  SetMaterial( ({ "wood","metal" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}

