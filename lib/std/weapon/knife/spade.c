#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("spade");
  SetId( ({ "spade" }) );
  SetAdjectives( ({ "wooden" }) );
  SetShort("a wooden spade");
  SetLong(
    "Barely recognizable as a humanoid made tool, "
    "this bundle of branches and threaded vine fulfills "
    "the bare minimum requirements of spadehood."
  );
  SetMass(10);
  SetValue(25);
  SetClass(15);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetDamagePoints(500);
  SetMaterial( ({ "wood" }) );
  SetProperty(
    "history","Somebody stole this from a poor kobold that had "
    "precious little to begin with. Whoever holds it is pretty much "
    "a bastard."
  );
}

