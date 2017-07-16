
/* This is the shell of the hermit crab coded by Lynna on February 11, 1998
*/
#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName( "crab shell" );
  SetShort( "a small shell" );
  SetId( ({ "shell", "crab shell" }) );
  SetAdjectives( ({ "crab", "small" }) );
  SetLong( "This crab shell is left on the shore by the "
           "hermit crabs." );
  SetSize(SIZE_VERY_SMALL);
  SetArmourClass(ARMOUR_NATURAL);
  SetArmourType(A_ARMOUR);
  SetMass(5);
  SetDamagePoints(150);
  SetValue(15);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(5);
  SetWarmth(5);
  SetRepairSkills( ([
    "natural working" : 4,
    ]) );
 }
