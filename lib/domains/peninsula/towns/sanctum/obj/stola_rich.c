// mahkefel 2011
// sanctum clothes
// fancy stola
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
  SetKeyName("stola");
  SetId( ({ "stola" }) );
  SetShort("a red silk stola");
  SetAdjectives( ({ "red","silk" }) );
  SetLong(
    "This red dyed cloth garment hangs from the shoulders "
    "and is belted around the midsection and waist. The "
    "knees and ankles are covered with a many-folded dress."
  );
  SetWarmth(10);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetMass(80);
  SetValue(1000);
  SetDamagePoints(2000);
}

