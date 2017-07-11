/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: black_robe.c
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
  SetKeyName("black robe");
  SetId( ({ "robe" }) );
  SetAdjectives( ({"black","long","and"}) );  
  SetShort("a long and black robe");
  SetLong("This is a long, black robe made out of velvet. "
          "It has a golden string around the waist to "
          "be able to adjust it to the body.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetMass(100);
  SetValue(200);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetMaterials( ({ "textile","natural" }) );
  SetWarmth(25);
  SetRepairDifficulty(20);
  SetRepairSkills( ([
                     "textile working" : 10,
                     "armour smithing" : 10,
                     "natural working" : 10
                 ]) );
  SetProperties( ([
                   "magic" : "The robe has been protected against "
                             "magic by a very powerful being.",
                   "history" : "Part of the history of this robe "
                               "has been lost over time, but the "
                               "remaining part tells of a very "
                               "powerful and ancient being calling "
                               "upon dark forces to implant on the "
                               "fibers that form the robe."
                ]) );
}
