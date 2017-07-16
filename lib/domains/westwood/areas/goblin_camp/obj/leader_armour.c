#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("armour");
  SetArmourType(A_BODY_ARMOUR);
  SetShort("a suit of chainmail");
  SetLong(
    "This is a suit of chain armour.  It is made of rings "
	"assembled into a tight mesh then riveted closed.  It is made to "
    "cover the torso and protect from slashing primarily.");
  SetValue(250);
  SetMass(180);
  SetDamagePoints(900);
  SetId( ({ "chainmail","armour" }) );
  SetAdjectives( ({ "suit" }) );
  // SetProtection(SLASH, 15);
  // SetProtection(PIERCE, 10);
  // SetProtection(BLUNT, 10);
  SetMaterial( ({ "metal" }) );
  SetArmourClass(ARMOUR_CHAIN);
  SetWarmth(0);
  SetRepairSkills( ([ 
    "metal working" : 2,
    "armour smithing" : 2,
    ]) );
  SetRepairDifficulty(3);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_LARGE);
}
