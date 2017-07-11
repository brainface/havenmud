#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("armour");
  SetArmourType(A_ARMOUR);
  SetShort("a suit of chainmail");
  SetLong("This is a suit of chain armour.  It is made of rings "
        "assembled into a tight mesh then riveted closed.  It is made to "
        "cover the torso and protect from slashing primarily.");
  SetValue(2500);
  SetMass(500);
  SetDamagePoints(2000);
   SetProperty("laoise_flag", 1);
  SetArmourClass(ARMOUR_CHAIN);
  SetId( ({ "chainmail","armour" }) );
  SetAdjectives( ({ "suit" }) );
  // SetProtection(SLASH, 35);
  // SetProtection(PIERCE, 15);
  // SetProtection(BLUNT, 15);
  // SetProtection(MAGIC, 35);
  // SetProtection(HEAT, 25);
  // SetProtection(COLD, 25);
  SetMaterial( ({ "metal" }) );
  SetWarmth(0);
  SetRepairSkills( ([ 
  			"metal working" : 20,
        "armour smithing" : 25,
        ]) );
  SetRepairDifficulty(25);
  SetVendorType(VT_ARMOUR);
}
