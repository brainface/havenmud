#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("oaken staff");
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "oaken" }) );
  SetShort("an oaken staff");
  SetLong(
    "This is a long oaken staff."
  );
  SetHands(2);
  SetClass(12);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(800);
  SetValue(80);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([
    "wood working" : 1,
    "weapon smithing" : 1,
     ]) );
 }
