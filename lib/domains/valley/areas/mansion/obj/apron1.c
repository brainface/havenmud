/* an apron for the cook
   kyla 9-98
*/
#include <lib.h>
#include "../mansion.h"
#include <armour_class.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("apron");
  SetShort("a dirty apron");
  SetId( ({"apron"}) );
  SetAdjectives( ({"dirty"}) );
  SetLong("This dirty apron looks as if it has endured several "
           "years in the kitchen.");
  SetMass(10);
  SetValue(10);
  SetVendorType(VT_ARMOUR);
  SetDamagePoints(50);
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_VEST);
  SetRepairSkills( ([
           ]) );
  SetMaterials( ({"textile"}) );
  SetWarmth(7);
  }
