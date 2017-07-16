#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
 
inherit LIB_ARMOUR;
 
static void create()
{
  string theColor;
 
  armour::create();
  SetKeyName("cloak");
 
  switch(random(7))
  {
    case 0: theColor = "red"; break;
    case 1: theColor = "brown"; break;
    case 2: theColor = "grey"; break;
    case 3: theColor = "black"; break;
    case 4: theColor = "green"; break;
    case 5: theColor = "beige"; break;
    case 6: theColor = "blue"; break;
  }
 
  SetId(( { "cloak" } ));
  SetAdjectives( ({ theColor }) );
  SetShort("a " + theColor + " cloak");
  SetLong("The " + theColor + " cloak is made of a soft material. It was designed "
          "to hide anyone who wears it. It has a large hood and two small chest "
          "pockets attached to it. ");
  SetMass(15);
  SetValue(200);
  SetDamagePoints(200);
  SetSize(SIZE_VERY_SMALL);
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
 
  SetWear("The cloak has a warm feel to it.");

  SetMaterial( ({ "textile" }) );
  SetWarmth(20);
  SetRepairDifficulty(35);
  SetRepairSkills( ([
                      "textile working" : 20,
                 ]) );
   SetProperty("magic","This cloak magically changes color.");
}




