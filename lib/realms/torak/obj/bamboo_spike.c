#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("spike");
  SetClass(22);
  SetDamagePoints(1400);
  SetValue(100);
  SetWeaponType("pole");
  SetShort("a bamboo spike");
  SetHands(2);
  SetId( ({ "spike" }) );
  SetAdjectives( ({ "bamboo" }) );
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(20);
  SetDamageType(PIERCE|BLUNT);
  SetVendorType(VT_WEAPON);
  SetLong("The bamboo spike is long and solid. It is yellow with "
    "grey rings where the columns formed during its life. Both ends "
    "of the spike have been cut to sharp points and treated with fire "
    "to harden and stengthen them.");
  SetMass(48);
}
