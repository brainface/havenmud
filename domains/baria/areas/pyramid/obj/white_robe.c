/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: white_robe.c
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
  SetKeyName("white robe");
  SetId( ({ "robe" }) );
  SetAdjectives( ({"white","beautiful"}) );  
  SetShort("a beautiful white robe");
  SetLong("A very nice white robe made for dressing "
          "purposes rather than for protection.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_CLOAK);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(35);
  SetValue(100);
  SetDamagePoints(100);
  SetSize(SIZE_MEDIUM);
  SetMaterials( ({ "textile" }) );
  SetWarmth(15);
  SetRepairDifficulty(5);
  SetRepairSkills( ([
                     "textile working" : 1,
                     "armour smithing" : 1,
                 ]) );
}
