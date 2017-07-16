#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
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
  SetWarmth(10);
  SetSize(SIZE_SMALL);
  SetArmourClass(ARMOUR_LEATHER);
  SetValue(220);
  SetMaterial("leather");
  SetRepairDifficulty(5);
  SetDamagePoints(450);
  // SetProtection(BLUNT, 10);
  // SetProtection(PIERCE, 5);
  // SetProtection(SLASH, 10);
  SetArmourType(A_ARMOUR);
}
