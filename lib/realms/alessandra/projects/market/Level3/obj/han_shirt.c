#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("shirt");
  SetId( ({"shirt"}) );
  SetAdjectives( ({"handsome"}) );
  SetShort("a handsome shirt");
  SetLong(
     "This handsome shirt is made of a crisp white material. The sleeves are "
     "long, and the front is lined with pearl colored buttons."
     );
  SetMass(30);
  SetWarmth(20);
  SetSize(SIZE_MEDIUM);
  SetValue(390);
  SetVendorType(VT_ARMOUR);
  SetDamagePoints(90);
  SetRestrictLimbs( ({ "torso", "right arm", "left arm" }) );
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_ARMOUR);

}


