#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("chainmail");
  SetId( ({"chainmail"}) );
  SetShort("a skin covered chainmail");
  SetLong(
     " "
     ); 
  SetAdjectives( ({"skin"}) );
  SetMass(450);
  SetValue(310);
  SetMaterial( ({"skin","metal"}) );
  SetWarmth(10);
  SetRepairSkills( ([
  "armour smithing" : 7,
  "metal working" : 7,
  ]) );
  SetRepairDifficulty(18);
  SetDamagePoints(700);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_MAX_ARMOUR_BIT);
  SetProtection(SLASH,25);
  SetProtection(BLUNT,20);
  SetProtection(PIERCE,25);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:30:26 2000. */
