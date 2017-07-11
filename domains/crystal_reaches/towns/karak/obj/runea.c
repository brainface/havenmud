// Karak Rewrite
// Laoise
// 2007

#include <lib.h>
#include <size.h>
#include "../karak.h"
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("rune armour");
  SetId( ({ "armour" }) );
  SetAdjectives( ({ "black", "rune" }) );
  SetShort("black rune armour");
  SetLong(
    "Crafted of hardened leather and made to be close-fitting, this armour "
    "suggests the outline of a large torso. Its front has been carefully "
    "crafted with runes of protection and the worship of evil. Its arm "
    "portions are attached with durable leather strapping and buckles. "
  );
  SetArmourClass(ARMOUR_LEATHER);
  SetArmourType(A_ARMOUR);
  SetSize(SIZE_LARGE);
  SetMass(100);
  SetValue(1000);
  SetDamagePoints(1000);
  SetWarmth(0);
  SetMaterials( ({
  	"leather",
  }) );
  SetRepairDifficulty(30);
}
