#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ITEM;

static void create() {
  item::create();

  SetKeyName("sword");
  SetId( ({"sword"}) );
  SetShort("a bearteeth sword");
  SetLong(
    " "
    );
  SetClass(20);
  SetAdjectives( ({"bearteeth"}) );
  SetValue(250);
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamagePoints(300);
  SetMaterial( ({"bone","leather"}) );
  SetRepairSkills( ([
  "weapon smithing" : 7,
  ]) );
  SetRepairDifficulty(5);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:29:11 2000. */