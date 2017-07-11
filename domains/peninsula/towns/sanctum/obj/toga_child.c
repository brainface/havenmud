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
  SetKeyName("toga");
  SetId( ({ "toga" }) );
  SetShort("a purple striped toga");
  SetAdjectives( ({ "purple","striped" }) );
  SetLong(
    "This simple cloth garment consists of a white cloth "
    "with purple border draped over the shoulders of the "
    "wearer like a sheet. The previous wearer has decorated "
    "the pristine cloth with copious amounts of dirt and grime. "
  );
  SetWarmth(10);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetMass(80);
  SetValue(50);
  SetDamagePoints(2000);
}

