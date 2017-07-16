#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

int CheckRace();

static void create() 
{
    armour::create();
    SetKeyName("breeches");
   SetId( ({ "breeches","pants" }) );
   SetAdjectives( ({ "small","leather","halfling","well-worn" }) );
    SetShort("small leather breeches");
    SetLong("Signs of wear mark the knees and cuffs of the leather breeches.");
    SetVendorType(VT_ARMOUR);
    SetMass(50);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_SMALL);
    SetMaterial("leather");
    SetWarmth(20);
    SetValue(80);
    SetDamagePoints(400);
    SetArmourType(A_PANTS);
    SetWear( (: CheckRace :));
}

int CheckRace()
{
  if( (string)this_player()->GetRace() == "halfling" )
    {
      write("The breeches slip snuggly on your legs.");
      say((string)this_player()->GetName() + " wears leather breeches.");
      return 1;
    }
  else
    {
      write("The breeches aren't the right size for you.");
      say((string)this_player()->GetName() + " attempts to wear leather "
            "breeches.");
      return 0;
    }
}
