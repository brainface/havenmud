#include <lib.h>
#include "../karak.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("flail");
  SetId( ({ "flail" }) );
  SetShort( "a wickedly spiked flail");
  SetLong("A large flail forged from iron, steel and brass.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(700);
  SetClass(14);
  SetValue(300);
  SetMass(200);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);

}
