#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("greaves");
  SetShort("a pair of plate mail greaves");
  SetId( ({ "greaves" }) );
  SetAdjectives( ({ "pair","plate", "mail" }) );
  SetArmourType(A_PANTS);
  SetSize(SIZE_MEDIUM);
  SetLong("This pair of greaves are made from metal and appear to be very sturdy. "
    "The plated greaves are etched with coiling snakes wrapping around the entire "
    "leg.");
  SetValue(1500);
  SetMass(200);
  SetDamagePoints(25000);
  SetArmourClass(ARMOUR_PLATE);
  SetMaterial( ({ "metal" }) );
  SetRepairDifficulty(85);
  SetWarmth(0);
  SetVendorType(VT_ARMOUR);
 }
