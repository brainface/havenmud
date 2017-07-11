//Selket@Haven
//2006
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetKeyName("spear");
  SetShort("a heavy spear");
  SetMass(90);
  SetClass(15);
  SetValue(90);
  SetDamagePoints(1000);
  SetId( ({ "spear" }) );
  SetAdjectives( ({ "heavy", "wooden", }) );
  SetLong(
    "This long spear has a bronze tip that seems extremely "
    "sharp and pointy. "
    );
  SetVendorType(VT_WEAPON);
}
