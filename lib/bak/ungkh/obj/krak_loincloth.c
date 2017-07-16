#include <lib.h>
#include "../ungkh.h"
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();

  SetKeyName("loincloth");
  SetId( ({ "loincloth" }) );
  SetAdjectives( ({ "dirty" }) );

  SetShort("a dirty loincloth");
  SetLong("This loincloth is falling apart and smelly.  Mud stains "
          "cover the entire surface.  Made from the fur of local "
          "animals, it smells horribly.");

  SetVendorType(VT_CLOTHING);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_LARGE);
  SetWarmth(10);
  SetDamagePoints(260);
  SetArmourType(A_PANTS);
  
  SetMaterial("textile");
  SetMass(125);

  SetRepairDifficulty(3);
  SetRepairSkills( ([
    "armour smithing" : 3,
    "textile working" : 2,
    ]) );

  SetValue(10);

}
