#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
 
inherit LIB_ARMOUR;
 
static void create()
{
  string theColor;
 
  armour::create();
  SetKeyName("cape");
 
  switch(random(7))
  {
    case 0: theColor = "red"; break;
    case 1: theColor = "brown"; break;
    case 2: theColor = "grey"; break;
    case 3: theColor = "black"; break;
    case 4: theColor = "green"; break;
    case 5: theColor = "beige"; break;
    case 6: theColor = "plaid"; break;
  }
 
  SetId(( { "cape" } ));
  SetAdjectives( ({ theColor }) );
  SetShort("a " + theColor + " cape");
  SetLong(
    "The " + theColor + " cape is made of a soft material. "
    "It appears to be of a size suitable for the smaller races. "  
  );
  SetMass(25);
  SetValue(20);
  SetArmourClass(ARMOUR_CLOTH);
  SetDamagePoints(200);
  SetSize(SIZE_SMALL);
 
 
  SetArmourType(A_CLOAK);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
 
  SetWear("The cape has an aristocratic feel to it.");

  SetMaterial( ({ "textile" }) );
  SetWarmth(20);
  SetRepairDifficulty(1);
  SetRepairSkills( ([
                      "textile working" : 1,
                 ]) );
   SetProperty("magic","This cape magically changes color.");
}
