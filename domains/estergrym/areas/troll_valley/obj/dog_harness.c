/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;


static void create() 
{
  armour::create();
  SetKeyName("dog harness");
  SetId( ({ "dog harness","harness" }) );
  SetAdjectives( ({"leather"}) );
  SetShort("a leather harness");
  SetLong("Clasps, buckles and rings make the dog harness jingle.");
  SetVendorType(VT_ARMOUR);
  SetMass(75);
  SetArmourClass(ARMOUR_LEATHER);
  SetValue(30);
  SetDamagePoints(600);
  // SetProtection(BLUNT, 1);
  // SetProtection(PIERCE, 1);
  // SetProtection(SLASH, 1);
  SetArmourType(A_ARMOUR);
  SetMaterial( ({"leather"}) );
  SetWarmth(0);
  SetSize(SIZE_VERY_SMALL);
  SetRepairSkills( ([
     "leather working" : 3,
     ]) );
  SetRepairDifficulty(25);
}
