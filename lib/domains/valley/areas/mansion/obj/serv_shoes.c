/* shoes for the servants
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
  SetKeyName("shoes");
  SetId( ({"shoes"}) );
  SetAdjectives( ({"black"}) );
  SetShort("a pair of black shoes");
  SetLong("These shoes look to be very inexpensive, and well-worn.");
  SetMass(20);
  SetDamagePoints(300);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_ARMOUR);
  SetValue(20);
  SetArmourType(A_BOOT);
  SetMaterials( ({"leather"}) );
  SetWarmth(4);
  SetRepairSkills( ([
          "leather working" : 2,
              ]) );
  SetRepairDifficulty(8);
  SetProperty( "multiples", 1);
  }
