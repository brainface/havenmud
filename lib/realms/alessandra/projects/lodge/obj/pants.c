#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("pants");
  SetId( ({"pants"}) );
  SetShort("a pair of flesh made pants");
  SetLong(
     " "
     );
  SetAdjectives( ({"flesh"}) );
  SetMass(120);
  SetValue(75);
  SetMaterial( ({"skin"}) );
  SetWarmth(15);
  SetRepairSkills( ([
  "amour smithing " : 4,
  ]) );
  SetRepairDifficulty(9);
  SetDamagePoints(410);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_PANTS);
  SetProtection(SLASH,10);
  SetProtection(PIERCE,10);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:27:02 2000. */
