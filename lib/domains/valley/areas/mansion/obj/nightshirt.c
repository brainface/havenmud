/* a baby's nightshirt
    kyla 9-98
*/
#include <lib.h>
#include <armour_class.h>
#include "../mansion.h"
#include <vendor_types.h>
#include <armour_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;
int CheckBaby();

static void create() {
  armour::create();
  SetKeyName("a nightshirt");
  SetId( ({"shirt", "nightshirt"}) );
  SetAdjectives( ({"white", "night"}) );
  SetShort("a white nightshirt");
  SetLong("This white nightshirt is very small and would only "
        "fit a human child, or something of equivilent size.");
  SetMass(25);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetValue(10);
  SetDamagePoints(100);
  SetArmourType(A_SHIRT);
  SetMaterials( ({"textile"}) );
  SetWarmth(4);
  SetRepairSkills( ([
          ]) );
  SetWear( (:CheckBaby:) );
  }

int CheckBaby() {
  if(this_player()->GetKeyName() == "baby") {
    return 1;
  }
  else { 
  message("system", "The nightshirt is far too small to wear.",
           this_player());
    return 0;
  }
}
