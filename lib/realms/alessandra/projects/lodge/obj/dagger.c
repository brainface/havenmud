#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("dagger");
  SetId( ({"dagger"}) );
  SetShort("a glazed dagger");
  SetLong(
     " "
     );
  SetClass(12);
  SetAdjectives( ({"glazed"}) );
  SetValue(500);
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetWeaponType("knife");
  SetDamagePoints(500);
  SetMaterial( ({"mithril","glass"}) );
  SetRepairSkills( ([
  "mithril working" : 10,
  "weapon smithing" : 10,
  ]) );
  SetRepairDifficulty(11);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:26:09 2000. */
