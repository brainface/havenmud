#include <lib.h>
#include "../ungkh.h"
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("hammer");
  SetId( ({ "hammer" }) );
  SetAdjectives( ({ "forge" }) );

  SetShort("a forge hammer");
  SetLong(
    "This forge hammer has a 4 foot haft with a large lump"
    " of iron on the end. Designed for hammering out metal,"
    " it could easily be used to brain someone.");

  SetVendorType(VT_WEAPON);
  SetDamagePoints(500);

  SetClass(7);
  SetMaterial("metal");
  SetMass(125);
  SetWeaponType("blunt");

  SetDamageType(BLUNT);
  SetValue(75);

  SetRepairDifficulty(3);
  SetRepairSkills( ([
    "weapon smithing" : 3,
    "metal working" :2,
    ]) );

}
