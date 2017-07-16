#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("hide");
  SetId( ({"hide"}) );
  SetShort("a deerskin hide");
  SetLong(
     " "
     );
  SetAdjectives( ({"deerskin"}) );
  SetMass(400);
  SetValue(400);
  SetMaterial( ({"fur","skin"}) );
  SetWarmth(20);
  SetRepairSkills( ([
     "armour smithing" : 6,
  ]) );
  SetRepairDifficulty(6);
  SetDamagePoints(600);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_ARMOUR);
  SetProtection(SLASH,8);
  SetProtection(BLUNT,5);
  SetProtection(PIERCE,6);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:25:51 2000. */
