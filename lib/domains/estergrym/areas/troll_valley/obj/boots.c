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
  SetKeyName("boots");
  SetId( ({ "boots","leather boots" }) );
  SetShort("leather boots");
  SetLong("Scuff marks mar the toes of these leather boots.");
  SetVendorType(VT_ARMOUR);
  SetMass(50);
  SetValue(80);
  SetProperty("multiples", 1);
  SetDamagePoints(400);
  // SetProtection(BLUNT, 2);
  // SetProtection(PIERCE, 2);
  // SetProtection(SLASH, 2);
  // SetProtection(COLD,2);
  SetArmourType(A_BOOT);
   SetArmourClass(ARMOUR_LEATHER);
  SetMaterial( ({"leather"}) );
  SetWarmth(5);
  SetSize(SIZE_SMALL);
  SetRepairSkills( ([
     "leather working" : 3,
     ]) );
  SetRepairDifficulty(10);
}
