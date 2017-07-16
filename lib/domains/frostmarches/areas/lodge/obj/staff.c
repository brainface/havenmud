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
  SetLong("This staff is made of the femur from a enormous animal.  "
  "It is quite clean, for there is no trace of blood on it.  Carved in "
  "the staff, are symbols and shapes, which in some bizarre language, "
  "probably means something of great importance.");
  SetClass(17);
  SetAdjectives( ({"thick"}) );
  SetValue(250);
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetWeaponType("pole");
  SetDamagePoints(150);
  SetMaterial( ({"natural"}) );
  SetRepairSkills( ([
  "weapon smithing" : 4,
  ]) );
  SetRepairDifficulty(8);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:28:55 2000. */