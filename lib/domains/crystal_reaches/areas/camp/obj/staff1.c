
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../camp.h"
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("staff");
  SetShort("a decorated staff");
  SetLong("The long staff is made of oak.  Vines, "
      "flowers, and birds have been carved lightly into "
      "the wood and painted brightly.");
  SetHands(2);
  SetId( ({ "staff" }) );
  SetAdjectives( ({ "decorated" }) );
  SetClass(13);
  SetWeaponType("pole");
  SetDamageType(BLUNT);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(950);
  SetValue(100);
  SetMass(200);
  SetMaterials( ({ "wood" }) );
  SetRepairDifficulty(5);
  SetRepairSkills( ([
     "wood working" : 1,
     "weapon smithing" : 1,
     ]) );
   SetProperty("history","A gypsy made "
      "this staff.  The carvings show the "
      "connection the gypsy had to nature.");
 }
