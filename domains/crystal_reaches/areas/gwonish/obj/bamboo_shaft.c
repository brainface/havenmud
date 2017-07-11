// torak 10/27/12
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("bamboo shaft");
  SetClass(14);
  SetDamagePoints(1000);
  SetValue(20);
  SetWeaponType("pole");
  SetShort("a bamboo shaft");
  SetHands(2);
  SetId( ({ "shaft" }) );
  SetAdjectives( ({ "bamboo" }) );
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(10);
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetLong("The bamboo shaft is long and solid. It is yellow with "
    "grey rings where the columns formed during its life.");
  SetMass(50);
}

// mahkefek 2017: allowing it to be made into yarn and thread.
// (thread is a bit anachronistic but whatev)
direct_spin_str_from_obj() {
  return 1;
}
