/*  Portia  10-14-98
    A breastplate for the guards.
*/

#include <lib.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("breastplate");
  SetShort("a shiny breastplate");
  SetId( ({"breastplate", "plate"}) );
  SetAdjectives( ({"breast", "shiny"}) );
  SetLong("This breastplate made of a very shiny metal. There seems to "
         "be an imprint of a rose down the middle.");
  SetValue(300);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(1500);
  SetMass(150);
  SetMaterials( ({"metal"}) );
  SetWarmth(0);
  SetRepairSkills( ([
      "metal working" : 7,
          ]) );
  SetRepairDifficulty(70);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_VEST);
  // SetProtection(BLUNT,6);
  // SetProtection(SLASH,6);
  // SetProtection(PIERCE,6);
  // SetProtection(HEAT,6);
  }
