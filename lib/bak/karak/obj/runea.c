#include <lib.h>
#include <size.h>
#include "../karak.h"
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("armour");
  SetId( ({ "armour", "armor" }) );
  SetAdjectives( ({ "black","rune" }) );
  SetShort("black rune armour");
  SetLong("A close-fitting suit of a thin but extremely strong steel, "
          "lovingly engraved with runes of protection.");
  SetMass(100);
  SetSize(SIZE_LARGE);
  SetWarmth(0);
  SetArmourClass(ARMOUR_PLATE);
  SetValue(1250);
  SetDamagePoints(1000);
  // SetProtection(BLUNT, 15);
  // SetProtection(SLASH, 22);
  // SetProtection(PIERCE, 18);
  SetArmourType(A_ARMOUR);
}
