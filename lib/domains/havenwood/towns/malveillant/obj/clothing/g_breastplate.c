/*  Portia  10-14-98
    A breastplate for the guards.
*/

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
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
  SetValue(150);
  SetMass(150);
  SetDamagePoints(800);
  SetArmourClass(ARMOUR_PLATE);
  SetSize(SIZE_MEDIUM);
  SetMaterials( ({"metal"}) );
  SetWarmth(0);
  SetRepairSkills( ([
      "armour smithing" : 5,
      "metal working" : 5,
          ]) );
  SetRepairDifficulty(60);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_VEST);
  // SetProtection(BLUNT,6);
  // SetProtection(SLASH,6);
  // SetProtection(PIERCE,6);
  // SetProtection(HEAT,6);
  }
