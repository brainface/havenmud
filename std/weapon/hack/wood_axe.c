#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  item::create();
  SetKeyName("wood axe");
  SetId( ({"axe"}) );
  SetAdjectives( ({ "wood" }) );
  SetShort("a wood axe");
  SetLong(
    "An axe like this leans up against every "
    "woodsman's house in Kailie. It has a plain "
    "wooden handle and a simple metal head."
  );
  SetClass(9);
  SetDamagePoints(750);
  SetValue(180);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetKeyName("axe");
  SetMass(75);
  SetMaterial( ({ "wood", "metal" }) );
  SetVendorType(VT_WEAPON);
}
