#include <lib.h>
#include "../ungkh.h"
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("knife");
  SetId( ({ "knife" }) );
  SetAdjectives( ({ "dirty" }) );

  SetShort("a dirty knife");
  SetLong("Used as the primary weapon of weak goblins, this knife "
          "is reliable enough to use.  It is dirty and covered with "
          "mud.");

  SetVendorType(VT_WEAPON);
  SetDamagePoints(350);

  SetClass(6);
  SetMaterial("metal");
  SetMass(100);
  SetWeaponType("knife");
  SetDamageType(PIERCE);
  SetValue(50);

  SetRepairDifficulty(3);
  SetRepairSkills( ([
    "weapon smithing" : 3,
    "metal working" : 2,
    ]) );

}
