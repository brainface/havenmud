#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  ::create();
  SetId( ({"hatchet"}) );
  SetAdjectives( ({ "bladed","steel" }) );
  SetShort("a steel bladed hatchet");
  SetLong(
    "This appears to be a light weight, one handed mini "
    "axe. Its headpiece is made of steel and has been forged to "
    "wedge into the polished wooden handle firmly. The "
    "bladed edge has been blunted down to provide more "
    "of a sinister impact. Wax twine has been wrapped "
    "firmly around the handle to improve grip and has also "
    "been spun around the hatchet blade to keep it wedged "
    "into the wood."
  );
  SetClass(27);
  SetDamagePoints(2200);
  SetValue(940);
  SetWeaponType("hack");
  SetDamageType(BLUNT);
  SetKeyName("hatchet");
  SetMass(35);
  SetMaterial( ({ "metal","wood" }) );
  SetVendorType(VT_WEAPON);
  SetRepairDifficulty(20);
}