#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("gythka");
  SetShort("a long spiked gythka");
  SetId( ({ "gythka" }) );
  SetAdjectives( ({ "spiked", "long" }) );
  SetLong(
    "This gythka is made from a long iron staff "
    "tipped with a vicious chatkcha at each end.  "
    "The chatkchas are three-pronged stars made "
    "of some form of resin."
  );
  SetWeaponType("pole");
  SetDamageType(PIERCE|SLASH);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({ "metal", "natural" }) );
  SetClass(40);
  SetDamagePoints(5000);
  SetValue(random(500)+2000);
  SetMass(180);
  SetHands(2);
  SetRepairDifficulty(20);
}
