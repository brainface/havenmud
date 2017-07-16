#include <lib.h>
#include "../karak.h"
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("armor");
  SetId( ({ "armour", "armor" }) );
  SetShort("composite torso armor");
  SetLong("A suit of armor comprised of a metal breastplate fitted to a "
          "chainmail jerkin with strips of leather.  The plate is thin "
          "and made from the same dark metal as the chainmail.  This suit "
          "appears to be fairly light and consistently protective and "
          "sturdy.");
  SetSize(SIZE_LARGE);
  SetArmourClass(ARMOUR_CHAIN);
  SetMass(125);
  SetWarmth(15);
  SetValue(2500);
  SetDamagePoints(600);
  // SetProtection(BLUNT, 14);
  // SetProtection(SLASH, 18);
  // SetProtection(PIERCE, 15);
  SetArmourType(A_ARMOUR);
}
