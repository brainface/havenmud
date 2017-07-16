#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("armour");
  SetShort("a suit of chitin armour");
  SetId( ({ "suit", "armour" }) );
  SetAdjectives( ({ "chitin", "suit of" }) );
  SetLong("This is a large suit of chitin armour. It has been made"
          " from the exoskeleton of a deceased thri-kreen. It is a sandy"
          " brown in color and is very thick which suggests it is"
          " quite durable.");
  SetDamagePoints(600);
  SetValue(1500);
  SetArmourClass(ARMOUR_NATURAL);
  SetMass(450);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_ARMOUR);
  SetSize(SIZE_LARGE);
  SetMaterial( ({ "natural" }) );
  SetRepairDifficulty(35);
  SetWarmth(0);
}
