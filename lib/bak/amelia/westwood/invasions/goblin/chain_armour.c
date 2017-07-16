#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("armour");
  SetArmourType(A_ARMOUR);
  SetShort("a suit of chainmail");
  SetLong("This is a very low end suit of chain armour.  It is made of rings "
	"assembled into a tight mesh then riveted closed.  It is made to "
	"cover the torso and protect from slashing primarily.");
  SetValue(175);
  SetMass(250);
  SetDamagePoints(600);
  SetId( ({ "chainmail","armour" }) );
  SetAdjectives( ({ "suit" }) );
  SetProtection(SLASH, 8);
  SetProtection(PIERCE, 4);
  SetProtection(BLUNT, 6);
  SetMaterial( ({ "metal" }) );
  SetWarmth(0);
  SetRepairSkills( ([ "armour smithing" : 2,
	"metal working" : 1 ]) );
  SetRepairDifficulty(3);
  SetVendorType(VT_ARMOUR);
 }

/* Approved by Dylanthalus on Tue May 18 01:01:12 1999. */
