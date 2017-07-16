#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather tunic");
  SetId( ({ "tunic" }) );
  SetAdjectives( ({ "leather" }) );
  SetShort("a leather tunic");
  SetLong("The tunic appears quite servicable.");
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_ARMOUR);
  SetArmourClass(ARMOUR_LEATHER);
  SetMaterial("leather");
  SetRepairDifficulty(5);
  SetMass(150);
  SetWarmth(10);
  SetValue(220);
  SetDamagePoints(450);
  SetSize(SIZE_SMALL);
}
