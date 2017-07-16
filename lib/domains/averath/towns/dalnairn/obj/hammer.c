#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
item::create();
  SetKeyName("hammer");
  SetId( ({ "war hammer","hammer" }) );
  SetShort("a war hammer");
  SetLong("A heavy black iron head is fixed to a sturdy long wooden "
          "handle. A rose is etched into each side of the hammer's "
          "head.  It can be quite formidable when used effectively.");
  SetMass(300);
  SetValue(1000);
  SetHands(2);
  SetDamagePoints(1200);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(18);
  SetVendorType(VT_WEAPON);
  SetMaterial( ({"metal","wood"}) );
  SetRepairDifficulty(25);
}
