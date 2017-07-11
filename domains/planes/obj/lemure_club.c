// lemure blunt weapon
// mahk apr '10
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("femur");
  SetId( ({ "femur" }) );
  SetAdjectives( ({ "humanoid" }) );
  SetShort("a bloody femur");
  SetLong(
    "This appears to be a still bloody humanoid"
    " femur, possibly from some luckless adventurer."
  );
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1500);
  SetValue(200);
  SetClass(14);
  SetMass(100);
  SetMaterial( ({ "natural" }) );
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
}

