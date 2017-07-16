//
// magical armour
// created by Ranquest@Haven
//
#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include "main.h"
#include <damage_types.h>
 inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetShort("a breastplate of chaos armour");
  SetLong("This armour seems to shine and glitter and swirl. Strange runes "
    "carved all over seem to twist and attempt to evade inspection.");
  SetKeyName("chaos armour");
  SetId(( {"armour", "breastplate", } ));
  SetAdjectives( ({"chaos", "of", "breastplate"}) );
  SetProperty("history",
    "This breastplate of chaos armour was originally one of twelve, forged by the"
    " legendary Yuk Foo Tuk for King Radchek's personal bodyguard. Seven of"
    " these breastplates have been recovered and lie in the homes of several of the"
    " most powerful adventurers around, and five were presumed lost forever"
    " or destroyed.");
  SetProperty("magic",
    "The breastplate of chaos armour resonates magic throughout. The runes scrawled"
    " over it look like very strong wards of protection from both magic and"
    " force of arms.");
  SetMass(200);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetSize(SIZE_MEDIUM);
  SetMaterial("metal");
  SetWarmth(0);
  SetRepairDifficulty(85);
  SetRepairSkills(( [
      "metal-working" : 3,
      "armour-smithing" : 3,
      ]) );
  SetValue(2000);
  SetDamagePoints(4000);
  // SetProtection(BLUNT, 8);
  // SetProtection(SLASH, 10);
  // SetProtection(MAGIC, 10);
  // SetProtection(PIERCE, 10);
  SetArmourType(A_VEST);
  //SetRestrictLimbs( ({ "right arm", "left arm", "torso" }) );
  SetWear("The power of pure chaos rages unbound.");
}


/* Approved by Duuktsaryth on Sun Nov 22 18:25:16 1998. */
