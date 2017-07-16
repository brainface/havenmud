#include <lib.h>
#include "../karak.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("flail");
  SetId( ({ "flail" }) );
  SetShort("a massive flail of black steel");
  SetLong("This huuuge flail is forged of a black metal.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1000);
  SetClass(16);
  SetValue(1000);
  SetMass(300);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);

}
