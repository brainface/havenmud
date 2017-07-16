#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetShort("a bone club");
  SetLong(
    "This \"club\" is rather nothing but the femur of some large beast. "
    "It has, thankfully, been bleached and cured so that no smelly "
    "marrow remains, though that likely will be little comfort to "
    "anyone that meets the ball joint at the end with their head."
  );
  SetId( ({"club","femur"}) );
  SetAdjectives( ({ "bone" }) );
  SetClass(15);
  SetDamagePoints(900);
  SetValue(350);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("club");
  SetMass(250);
  SetMaterial( ({ "natural" }) );
  SetVendorType(VT_WEAPON);
  SetHands(2);
}

