// mahkefel 2011
// sanctum clothes
// fancy toga
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
  SetShort("an embroidered toga");
  SetAdjectives( ({ "embroidered" }) );
  SetLong(
    "This cloth garment, little more than a sheet draped "
    "over the shoulders, has been embroidered with gold "
    "and silver leaves. A purple stripe along the border "
    "of the garment contrasts with the bright white of "
    "the body."
  );
  SetWarmth(10);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetMass(80);
  SetValue(1000);
  SetDamagePoints(2000);
}

