// mahkefel 2013
// lisht pole
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "gnarled" }) );
  SetShort("a gnarled staff");
  SetLong(
    "This sturdy sycamore branch is encircles by a dead vine "
    "spiralling up the staff like a snake. It looks to make "
    "a quite sturdy walking stick."
  );
  SetMass(90);
  SetValue(300);
  SetClass(20);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetDamagePoints(1500);
  SetMaterial( ({ "wood" }) );
}

