// mahkefel 2011
// MAN FUCK ELVES
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("timber");
  SetId( ({"timber"}) );
  SetAdjectives( ({ "broken" }) );
  SetShort("a broken timber");
  SetLong(
    "This jagged piece of wood seems to have been "
    "ripped entirely from whatever structure it once "
    "provided support to."
  );
  SetClass(10);
  SetDamagePoints(2000);
  SetValue(100);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetMass(500);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
  SetHands(1);
}
