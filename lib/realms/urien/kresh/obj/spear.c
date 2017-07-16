#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetHands(2);
  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetKeyName("wooden spear");
  SetShort("a long wooden spear");
  SetMass(80);
  SetClass(14);
  SetValue(80);
  SetDamagePoints(800);
  SetId( ({ "spear" }) );
  SetAdjectives( ({ "long", "wooden", }) );
  SetLong(
    "This spear is flimsy but effective.  It has a sharp, pokey "
    "end that can be roughly stabbed into someone should they "
    "hold still long enough."
    );
  SetVendorType(VT_WEAPON);
}

