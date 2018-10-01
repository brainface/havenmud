#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("armour");
  SetId( ({"suit","armour"}) );
  SetShort("a suit of composite armour");
  SetLong(
     " "
     );
  SetAdjectives( ({"composite"}) );
  SetMass(550);
  SetValue(300);
  SetMaterial( ({"metal","bone"}) );
  SetWarmth(5);
  SetRepairSkills( ([
     "metal working" : 6,
     "armour smithing" : 6,
  ]) );
  SetRepairDifficulty(15);
  SetDamagePoints(700);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetProtection(SLASH,20);
  SetProtection(BLUNT,15);
   SetProtection(PIERCE,20);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:28:35 2000. */
