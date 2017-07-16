#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("stone axe");
  SetId( ({"axe"}) );
  SetAdjectives( ({"stone", "hand"}) );
  SetShort("a stone axe");
  SetLong(
    "This is a hand axe that has a long wooden handle and "
    "a large stone head.  This axe seems a bit "
    "lighter than expected for a weapon made with a "
    "sharpened stone blade."
  );
  SetClass(9);
  SetDamagePoints(700);
  SetValue(180);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetKeyName("axe");
  SetMass(75);
  SetMaterial( ({ "wood", "natural" }) );
  SetVendorType(VT_WEAPON);
}
