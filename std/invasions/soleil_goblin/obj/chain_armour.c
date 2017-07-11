// Goblin invasion of Soleil
// Original Coder: Unknown
// Edited: Laoise, 2005

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("armour");
  SetShort("a suit of chainmail");
  SetId( ({ "chainmail","armour" }) );
  SetAdjectives( ({ "suit" }) );
  SetLong(
    "This is a very low end suit of chain armour. It is made of rings "
    "assembled into a tight mesh then riveted closed. It is made to "
    "cover the torso and protect from slashing primarily."
  );
  SetArmourType(A_ARMOUR);
  SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_CHAIN);
  SetValue(175);
  SetMass(250);
  SetWarmth(0);
  SetDamagePoints(600);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([ 
    "armour smithing" : 2,
    "metal working" : 1 
  ]) );
  SetRepairDifficulty(3);
}

/* Approved by Dylanthalus on Tue May 18 01:01:12 1999. */
