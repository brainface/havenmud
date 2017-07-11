#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("chatkcha");
  SetShort("a spiked chatkcha");
  SetId( ({ "chatkcha" }) );
  SetAdjectives( ({  "spiked" }) );
  SetLong(
    "This is a vicious looking three-pronged "
    "throwing star made from some "
    "crystalized form of resin.  It is "
    "sturdy but lightweight."
  );
  SetWeaponType("projectile");
  SetDamageType(PIERCE|SLASH);
  SetVendorType(VT_WEAPON);
  SetClass(35);
  SetDamagePoints(2500);
  SetValue(random(500)+1200);
  SetMass(35);
  SetMaterial("natural");
  SetHands(1);
  SetRepairDifficulty(20);
}
