#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("chigiriki");
  SetShort("an iron chigiriki");
  SetId( ({ "chigirki" }) );
  SetAdjectives( ({ "iron" }) );
  SetLong(
    "A short iron staff with a chain at the top "
    "connecting to an iron weight at the end.  "
    "The haft of the staff is beautifully engraved "
    "with desert flora and sand dunes."
  );
  SetWeaponType("melee");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetClass(35);
  SetDamagePoints(4000);
  SetValue(random(500)+1200);
  SetMass(180);
  SetMaterial("metal");
  SetRepairSkills( ([
     "metal working" : 2,
     "weapon smithing" : 2,
    ]) );
  SetHands(1);
  SetRepairDifficulty(20);
}
