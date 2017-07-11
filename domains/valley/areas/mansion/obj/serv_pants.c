/* pants for the servants of the mansion
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
  SetKeyName("pants");
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "black" }) );
  SetShort("a pair of black pants");
  SetLong("These pants do not appear to be of high quality.");
  SetMass(40);
  SetValue(20);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_ARMOUR);
  SetDamagePoints(300);
  SetArmourType(A_PANTS);
  SetMaterials( ({"textile"}) );
  SetWarmth(15);
  SetRepairSkills( ([
          ]) );
  }
