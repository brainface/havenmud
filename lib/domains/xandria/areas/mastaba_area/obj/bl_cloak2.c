//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("blue cloak");
  SetShort("a blue cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "blue" }) );
  SetLong(
    "This cloak is the color of the midday sky and "
    "appears to be very soft and protective.");
  SetMass(95);
  SetValue(85);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CLOTH);
  SetProperty("multiples", 1);
   SetSize(SIZE_MEDIUM);
  SetArmourType(A_CLOAK);
  SetDamagePoints(500);
  SetMaterial( ({ "textile" }) );
  SetWarmth(10);
}
