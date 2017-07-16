#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a club");
  SetLong(
     "This large piece of wood has been formed into a wieldable club for "
     "bludgeoning foes. "
  );
  SetId( ({ "club" }) );
  SetAdjectives( ({ }) );
  SetClass(5);
  SetDamagePoints(350);
  SetValue(50);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetKeyName("club");
  SetMass(75);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
}
