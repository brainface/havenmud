
#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("robe");
  SetShort("a robe made of daemon scales");
  SetId(  ({ "robe" })  );
  SetAdjectives(  ({ "daemon", "daemon scale", "scaled",
                     "scales" })  );
  SetLong("This robe has been crafted from the scales"
          " of a daemon. While not asthetically pleasing"
          " to look at, the rough and durable nature of"
          " daemon scales makes this robe very"
          " practical and effective as armour.");
  SetMass(120);
  SetValue(300);
  SetMaterial("natural");
  SetWarmth(20);
  SetDamagePoints(600);
  SetSize(SIZE_LARGE);
  SetArmourClass(ARMOUR_NATURAL);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_CLOTHING | VT_ARMOUR);
}
