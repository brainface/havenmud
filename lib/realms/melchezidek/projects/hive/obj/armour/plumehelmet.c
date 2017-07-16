#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helmet");
  SetShort("a large chitin helmet with a plume");
  SetId( ({ "helmet" }) );
  SetAdjectives( ({ "chitin", "large" }) );
  SetLong("This is a large helmet fashioned from the exoskeleton of a"
          " deceases thri-kreen. Along the middle ridge, there is a large"
          " purple plume of horsehair.");
  SetDamagePoints(600);
  SetValue(1500);
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(250);
  SetArmourType(A_HELMET);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_LARGE);
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(35);
  SetWarmth(0);
}
