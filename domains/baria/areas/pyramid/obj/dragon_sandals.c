/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: hell_sandals.c
// Area: the dark pyramid
//

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("dragon sandals");
  SetId( ({ "sandals" }) );
  SetAdjectives( ({"dragon","pair of"}) );  
  SetShort("a pair of dragon sandals");
  SetLong("This pair of sandals are made of a type of skin which has "
          "scales. The scales are of a blueish green tone and shimmer "
          "slightly at the glare of the sun." );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BOOT);
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(100);
  SetValue(700);
  SetDamagePoints(400);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({"natural"}) );
  SetWarmth(1);
  SetProperties( ([ 
                    "multiples" : 1,
                    "magic" : "These sandals offer protection "
                              "beyond physical damage.",
                    "history" : "This pair of sandals where made "
                                "from the skin of a death dragon "
                                "back in the GodsWar. They were "
                                "recently uncovered by Gihan, the "
                                "ruins examiner in some ruins."
               ]) );
  SetDestroyOnSell(1);
}
