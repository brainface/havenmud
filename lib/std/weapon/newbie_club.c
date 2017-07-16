#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetShort("a short wooden club");
  SetLong(
     "This large piece of wood has been formed into a wieldable club for "
     "bludgeoning foes. "
  );
  SetKeyName("club");
  SetId( ({ "club" }) );
  SetAdjectives( ({ "short", "wooden" }) );
  SetClass(5);
  SetDamagePoints(850);
  SetValue(00);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetMass(75);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
}
