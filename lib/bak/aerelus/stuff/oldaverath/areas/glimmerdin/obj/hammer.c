#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("iron hammer");
  SetId( ({ "hammer" }) );
  SetAdjectives( ({ "iron" }) );
  SetShort("an iron hammer");
  SetLong("This is a standard issue iron hammer used in "
          "Glistendin's forges.");
  SetMass(130);
  SetValue(250);
  SetDamagePoints(2000);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetClass(12);
  SetVendorType(VT_WEAPON);
}
