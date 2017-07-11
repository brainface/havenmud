/*  Portia 10-14-98
     Boots for the guards.
*/

#include <lib.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
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
  SetMaterial( ({"leather"}) );
  SetWarmth(5);
  SetDamagePoints(400);
  SetProperty("multiples", 1);
  SetRepairSkills( ([
            "leather working" : 8,
           ]) );
  SetRepairDifficulty(40);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_BOOT);
  SetVendorType(VT_ARMOUR);
  // SetProtection(BLUNT, 2);
  // SetProtection(PIERCE, 2);
  // SetProtection(COLD, 3);
  }
