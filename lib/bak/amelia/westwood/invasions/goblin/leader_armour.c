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
  SetLong("This is a suit of chain armour.  It is made of rings "
	"assembled into a tight mesh then riveted closed.  It is made to "
	"cover the torso and protect from slashing primarily.");
  SetValue(250);
  SetMass(250);
  SetDamagePoints(900);
  SetId( ({ "chainmail","armour" }) );
  SetAdjectives( ({ "suit" }) );
  SetProtection(SLASH, 12);
  SetProtection(PIERCE, 6);
  SetProtection(BLUNT, 8);
  SetMaterial( ({ "metal" }) );
  SetWarmth(0);
  SetRepairSkills( ([ "metal working" : 2,
	"armour smithing" : 2,
	]) );
  SetRepairDifficulty(3);
  SetVendorType(VT_ARMOUR);
}

/* Approved by Dylanthalus on Tue May 18 01:03:50 1999. */
