#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("boots");
  SetId( ({"boots"}) );
  SetAdjectives( ({"black","heavy","leather","pair", "of"}) );
  SetShort("a pair of black boots");
  SetLong(
    "This pair of boots has been polished black to protect "
    "the leather, as well as hide the metal heel and toes "
    "from casual inspection. The boots look very durable "
    "for basic wilderness use. "
    );
  SetMass(100);
  SetValue(50);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(500);
  SetWarmth(5);
  // SetProtection(BLUNT, 3);
  // SetProtection(SLASH, 3);
  // SetProtection(PIERCE, 3);
  // SetProtection(COLD, 1);
  SetArmourType(A_BOOT);
  SetSize(SIZE_SMALL);
  SetProperty("multiples", 1);
  SetMaterial( ({"leather"}) );
  SetRepairSkills( ([
    "armour smithing" : 5,
    "leather working" : 5,
    "metal working"   : 1,
    ]) );
  SetRepairDifficulty(10);
  }
