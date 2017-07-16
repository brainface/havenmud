// mahkefel 20101117
// MONKEY'S FIST!
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("monkey's fist");
  SetId( ({"fist","rope","knot"}) );
  SetAdjectives( ({ "monkey's" }) );
  SetShort("a monkey's fist");
  SetLong(
    "This short length of rope has an elaborate "
    "knot tied into one end to produce weight "
    "for throwing. While generally used to toss "
    "lines to other sailors, one cut short as this "
    "could only be meant for brawling."
  );
  SetClass(25);
  SetDamagePoints(2000);
  SetValue(2500);
  SetWeaponType("projectile");
  SetDamageType(BLUNT);
  SetMass(300);
  SetMaterial( ({ "textile" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}
