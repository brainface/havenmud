// mahkefel 20101117
// hey a mop
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("ragged mop");
  SetId( ({"mop"}) );
  SetAdjectives( ({ "ragged" }) );
  SetShort("a ragged mop");
  SetLong(
    "This mop is a long wooden pole capped with an assorted array "
    "of sliced leathers and canvas attached by a nail. The canvas "
    "is strangely rust-colored, as if stained."
  );
  SetClass(10);
  SetDamagePoints(2000);
  SetValue(100);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetMass(300);
  SetMaterial( ({ "wood","textile" }) );
  SetVendorType(VT_WEAPON);
  SetHands(2);
}

