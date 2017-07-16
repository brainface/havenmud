#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("vest");
  SetId( ({"vest"}) );
  SetShort("a vest of dismemberment");
  SetLong(
     " "
     );
  SetAdjectives( ({"dismembered"}) );
  SetMass(110);
  SetValue(175);
  SetMaterial( ({"skin"}) );
  SetWarmth(10);
  SetRepairSkills( ([
     "armour smithing" : 4,
  ]) );
  SetRepairDifficulty(9);
  SetDamagePoints(410);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_VEST);
  SetProtection(SLASH,10);
  SetProtection(PIERCE,10);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:30:14 2000. */
