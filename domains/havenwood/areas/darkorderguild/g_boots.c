/*  Portia 10-14-98
     Boots for the guards.
*/

#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetShort("a pair of heavy boots");
  SetId( ({"boots"}) );
  SetAdjectives( ({"heavy", "pair of",}) );
  SetLong("These boots are very well made and look like they would protect one's feet very well.");
  SetValue(70);
  SetMass(60);
  SetArmourClass(ARMOUR_LEATHER);
  SetSize(SIZE_MEDIUM);
  SetProperty("multiples", 1);
  SetMaterial( ({"leather"}) );
  SetWarmth(8);
  SetRepairSkills( ([
            "leather working" : 8,
           ]) );
  SetRepairDifficulty(40);
  SetArmourType(A_BOOT);
  SetVendorType(VT_ARMOUR);
  // SetProtection(BLUNT, 2);
  // SetProtection(PIERCE, 2);
  // SetProtection(COLD, 3);
  }
