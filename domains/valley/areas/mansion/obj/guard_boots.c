/* boots for the guards
   kyla 9-98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../mansion.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetShort("a nice pair of boots");
  SetId( ({"boots"}) );
  SetAdjectives( ({"nice", "pair", "pair of" }) );
  SetLong("These boots seem to be quite expensive, and are very "
           "well-made. The owner obviously cared for them a great deal.");
  SetValue(100);
  SetVendorType(VT_ARMOUR);
  SetDamagePoints(500);
  SetMass(40);
  // SetProtection(HEAT, 5);
  // SetProtection(PIERCE, 7);
  // SetProtection(COLD, 9);
  SetMaterials( ({"leather"}) );
  SetWarmth(8);
  SetRepairSkills( ([
          "leather working" : 9,
             ]) );
  SetRepairDifficulty(10);
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_BOOT);
  SetProperty("multiples", 1);
  } 
