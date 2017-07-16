// by Dahaka
// Aug 2004

#include <lib.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("hooded robe");
  SetId( ({"robe","hooded robe"}) );
  SetAdjectives( ({"hooded"}) );
  SetShort("a hooded robe");
  SetLong(
     "This dark hooded robe appears to be extra-ordinary. All though they appear "
     "to be just a pile of rags, there is a sub-liner under the outer material "
     "that is quite strong and durable. "
     );
  SetArmourType(A_BODY_ARMOUR);
  SetValue(4);
  SetMass(230);
  SetDamagePoints(2000);
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_ARMOUR);
  SetRepairDifficulty(35);
  SetRepairSkills( ([
     "textile working" : 2,
     ]) );
  SetMaterial( ({"textile"}) );
  SetWarmth(25);
}
