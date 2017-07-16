#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("mace");
  SetShort("a lightweight mace");
  SetId( ({ "mace" }) );
  SetAdjectives( ({ "light", "weight", "lightweight" }) );
  SetClass(9);
  SetDamagePoints(1200);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
  SetMaterial("metal");
  SetRepairDifficulty(5);
  SetMass(120);
  SetValue(0);
  SetLong("This small mace is of the lowest possible quality.");
  SetVendorType(VT_WEAPON);
}

  
