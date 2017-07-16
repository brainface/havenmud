#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather tunic");
  SetId( ({ "tunic" }) );
  SetAdjectives( ({ "leather" }) );
  SetShort("a leather tunic");
  SetLong("The tunic appears quite servicable.");
  SetMass(150);
  SetSize(SIZE_SMALL);
  SetValue(220);
  SetDamagePoints(450);
  // SetProtection(BLUNT, 10);
  // SetProtection(PIERCE, 5);
  // SetProtection(SLASH, 10);
  SetArmourType(A_ARMOUR);
}
