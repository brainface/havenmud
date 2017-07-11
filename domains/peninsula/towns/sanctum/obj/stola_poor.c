// mahkefel 2011
// sanctum clothes
// cheap stola
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
  SetShort("a yellow wool stola");
  SetAdjectives( ({ "yellow","wool" }) );
  SetLong(
    "This simple wool garment hangs from the shoulders "
    "and is belted around the midsection and waist. A "
    "few ribbons dangle from the belt along the folds of "
    "the dress."
  );
  SetWarmth(10);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetMass(80);
  SetValue(500);
  SetDamagePoints(2000);
}

