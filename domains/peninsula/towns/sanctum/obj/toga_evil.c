// mahkefel 2011
// sanctum clothes
// evil toga
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create(); 
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("toga");
  SetId( ({ "toga" }) );
  SetShort("an ashen black toga");
  SetAdjectives( ({ "ashen","black" }) );
  SetLong(
    "This unembroidered toga looks like it has been "
    "covered with charcoal. An intermittent pattern "
    "of black and grey smudges cover its surface."
  );
  SetWarmth(10);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetMass(80);
  SetValue(50);
  SetDamagePoints(2000);
}
