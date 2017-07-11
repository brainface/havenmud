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
  SetShort("a robe of daemonic origins");
  SetId(  ({ "robe" })  );
  SetAdjectives(  ({ "daemonic", "daemon" })  );
  SetLong("A combination of flesh and bone, this robe"
          " is grotesque. It's simple manufacture"
          " leaves much to be desired for asthetics"
          " but the bone reinforcement makes it a"
          " very formidable piece of equipment.");
  SetMass(120);
  SetValue(4000);
  SetMaterial("natural");
  SetWarmth(20);
  SetDamagePoints(1200);
  SetSize(SIZE_LARGE);
  SetArmourClass(ARMOUR_NATURAL);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_CLOTHING | VT_ARMOUR);
}
