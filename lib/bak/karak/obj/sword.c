#include <lib.h>
#include "../karak.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("sword");
  SetId( ({ "iron broadsword","broadsword","sword" }) );
  SetShort("an iron broadsword");
  SetLong("This weapon appears sturdy and dependable, if a bit plain.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(575);
  SetClass(12);
  SetValue(100);
  SetMass(75);
  SetWeaponType("slash");
  SetDamageType(SLASH);

}
