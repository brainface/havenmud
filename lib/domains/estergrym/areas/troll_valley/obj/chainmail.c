/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;


static void create() 
{
  armour::create();
  SetKeyName("chainmail");
  SetId( ({ "chain","chainmail" }) );
  SetAdjectives( ({"sturdy"}) );
  SetShort("sturdy chainmail");
  SetLong("Heavy gauge links are linked together forming a sturdy set of "
          "chainmail.");
  SetVendorType(VT_ARMOUR);
  SetMass(750);
   SetArmourClass(ARMOUR_CHAIN);
  SetValue(300);
  SetDamagePoints(600);
  // SetProtection(BLUNT, 1);
  // SetProtection(PIERCE, 4);
  // SetProtection(SLASH, 8);
  SetArmourType(A_ARMOUR);
  SetMaterial( ({"metal"}) );
  SetWarmth(0);
  SetSize(SIZE_SMALL);
  SetRepairSkills( ([
     "metal working" : 3,
     "armour smithing" : 3
     ]) );
  SetRepairDifficulty(25);
}
