#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("staff");
  SetId( ({"staff"}) );
  SetShort("a thick staff");
  SetLong(
     " "
     );
  SetClass(17);
  SetAdjectives( ({"thick"}) );
  SetValue(250);
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pole");
  SetDamagePoints(150);
  SetMaterial( ({"bone"}) );
  SetRepairSkills( ([
  "weapon smithing" : 4,
  ]) );
  SetRepairDifficulty(8);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:28:55 2000. */