//   by Alessandra 9/04    //

#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  
  SetKeyName("boots");
  SetShort("a pair of knee-high boots");
  SetId( ({"boots"}) );
  SetAdjectives( ({"knee-high", "pair of", "black", "leather"}) );
  SetLong(
     "These boots are very well made and quite fashionable, "
     "reaching nearly to ones knees. The black leather is polished "
     "to a shine."
     );
  SetMass(60);
  SetArmourClass(ARMOUR_LEATHER);
  SetWarmth(5);
  SetProperty("multiples", 1);
  SetValue(70);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(400);
  // SetProtection(BLUNT, 2);
  // SetProtection(PIERCE, 2);
  // SetProtection(COLD, 3);
  SetMaterial( ({"leather"}) );
  SetRepairSkills( ([
     "leather working" : 8,
     ]) );
  SetRepairDifficulty(40);
  SetArmourType(A_BOOT);
  SetVendorType(VT_ARMOUR);

  }
