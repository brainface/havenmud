#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("mace");
  SetShort("a heavy iron mace");
  SetId( ({ "mace" }) );
  SetAdjectives( ({ "heavy", "iron", "heavy iron" }) );
  SetClass(15);
  SetDamagePoints(1800);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetMass(180);
  SetValue(150);
  SetLong("This heavy iron mace is of top quality.");
  SetVendorType(VT_WEAPON);
}

  
