#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("hammer");
  SetId( ({ "war hammer","hammer" }) );
  SetShort("a war hammer");
  SetLong("A heavy iron head is fixed to a sturdy wooden handle. "
          "It can be quite formidable when used effectively.");
  SetMass(230);
  SetValue(150);
  SetDamagePoints(1200);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(20);
  SetVendorType(VT_WEAPON);
}
