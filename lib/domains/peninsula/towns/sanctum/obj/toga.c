// mahkefel 2011
// sanctum clothes
// simple toga
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
  SetShort("a white toga");
  SetAdjectives( ({ "white" }) );
  SetLong(
    "This cloth garment is little more than a sheet draped "
    "over the shoulders. It coveres the entire body, providing "
    "modesty and a little warmth."
  );
  SetWarmth(10);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);
  SetMass(80);
  SetValue(500);
  SetDamagePoints(2000);
}

