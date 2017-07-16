// mahkefel 2011
// sanctum clothes
// kid's tunic
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
  SetKeyName("tunic");
  SetId( ({ "tunic" }) );
  SetShort("a white tunic");
  SetAdjectives( ({ "white" }) );
  SetLong(
    "This simple tunic made of plain white cloth reaches "
    "nearly to the ankles of the wearer. A simple rope belt "
    "latches it at the waste, and the previous wearer has "
    "decorated it with dirt at the knees and elbows."
  );
  SetWarmth(10);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetMass(80);
  SetValue(50);
  SetDamagePoints(2000);
}

