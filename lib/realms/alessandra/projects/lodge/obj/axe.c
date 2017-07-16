#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("axe");
  SetId( ({"axe"}) );
  SetShort("a bony axe");
  SetLong(
     " "
     );
  SetClass(16);
  SetAdjectives( ({"bony"}) );
  SetValue(400);
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetWeaponType("hack");
  SetDamagePoints(750);
  SetMaterial( ({"bone","metal"}) );
  SetRepairSkills( ([
  "mithril working" : 10,
  "weapon smithing" : 10,
  ]) );
  SetRepairDifficulty(10);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:16:37 2000. */