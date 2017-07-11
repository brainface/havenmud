#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("hand crossbow");
  SetId( ({ "crossbow" }) );
  SetAdjectives( ({ "hand" }) );
  SetShort("a hand crossbow");
  SetLong(
    "This miniature crossbow is deviously constructed, but "
    "doesn't look like it could throw a bolt with much force. "
    "A laniard on the stock allows it to be wielded one handed."
  );
  SetClass(8);
  SetDamagePoints(800);
  SetValue(200);
  SetWeaponType("projectile");
  SetDamageType(PIERCE);
  SetHands(1);
  SetMass(25);
  SetMaterial( ({ "wood", "metal" }) );
  SetVendorType(VT_WEAPON);
}

