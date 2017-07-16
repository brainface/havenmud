#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  ::create();
  SetId( ({"staff"}) );
  SetAdjectives( ({ "gnarled","wooden" }) );
  SetShort("a gnarled wooden staff");
  SetLong(
    "It appears to have been plucked from nature with no craftsmanship "
    "whatsoever. Warped wood on the surface displays knots and wooden "
    "rings. Thin striped bark covers the outside making the surface "
    "appear rough."
  );
  SetClass(12);
  SetDamagePoints(1200);
  SetValue(150);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetKeyName("staff");
  SetMass(60);
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(10);
}