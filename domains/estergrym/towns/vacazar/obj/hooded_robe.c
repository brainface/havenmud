// Coded by Zeratul
// 3-23-2000

#include <lib.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include "../vacazar.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("hooded robe");
  SetId( ({"robe","hooded robe"}) );
  SetAdjectives( ({"hooded"}) );
  SetShort("a hooded robe");
  SetLong(
     "This dark hooded robe appears to be extra-ordinary. All though they appear "
     "to be just a pile of rags, there is a sub-liner under the outer material "
     "that is quite strong and durable. "
  );
  SetArmourType(A_BODY_ARMOUR);
  SetValue(400);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
  SetMass(230);
  SetDamagePoints(2000);
  // SetProtection(SLASH, 15);
  // SetProtection(PIERCE, 15);
  // SetProtection(BLUNT, 15);
  // SetProtection(MAGIC, 20);
  // SetProtection(SHOCK, 20);
  // SetProtection(ACID, 20);
  // SetProtection(HEAT, 12);
  // SetProtection(COLD, 22);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(35);
  SetRepairSkills( ([
     "armour smithing" : 20,
     "textile working" : 20,
  ]) );
  SetMaterial( ({"textile"}) );
  SetWarmth(25);
  }
