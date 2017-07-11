/* a breastplate for the guards
   kyla 9-98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include "../mansion.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("breastplate");
  SetShort("a large metal breastplate");
  SetId( ({"breastplate", "plate"}) );
  SetAdjectives( ({"large", "metal"}) );
  SetLong("This large metal breastplate looks as though it belongs "
         "to a warrior of high rank.");
  SetArmourType(A_VEST);
  SetVendorType(VT_ARMOUR);
  SetDamagePoints(1300);
  SetArmourClass(ARMOUR_PLATE);
  SetMass(150);
  SetValue(200);
  // SetProtection(BLUNT, 9);
  // SetProtection(SLASH, 9);
  // SetProtection(HEAT, 9);
  // SetProtection(PIERCE, 9);
  SetMaterials( ({"metal"}) );
  SetWarmth(0);
  SetRepairSkills( ([
          "metal smithing" : 7,
                 ]) );
  SetRepairDifficulty(8);
   }
