#include <lib.h>
#include "../ungkh.h"
#include <vendor_types.h>
#include <damage_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("mallet");
  SetId( ({ "mallet" }) );
  SetAdjectives( ({ "blacksmith's" }) );

  SetShort("a blacksmith's mallet");
  SetLong("Built to withstand great amounts of heat, this mallet "
          "was designed to be used as blacksmith's tool.  All though "
          "in times of dire need, it could be substituted for any "
          "weapon.");

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
