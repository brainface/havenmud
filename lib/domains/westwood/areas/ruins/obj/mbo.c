#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  ::create();
  SetId( ({"staff"}) );
  SetAdjectives( ({ "bo","wooden","long" }) );
  SetShort("a long wooden bo staff");
  SetLong(
    "This long staff has been crafted from one solid piece of wood. "
    "It is perfectly linear and shows no variation of curvature. A white "
    "sticky tape has been wrapped along the middle of this staff to "
    "allow for a more positive grip. This staff is very long, roughly the "
    "length of a tall orc. The black wood it was crafted with seems "
    "very durable and hardened. Its surface displays a slight sheen."
  );
  SetClass(21);
  SetDamagePoints(2200);
  SetValue(420);
  SetHands(2);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("bo");
  SetMass(70);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(15);
}