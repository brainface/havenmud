//-- Torak@Haven --//

#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("chainmail");
  SetId( ({ "chainmail" }) );
  SetShort("a suit of chainmail");
  SetLong("This chainmail is the common armour of lizardmen "
          "throughout the swamps.  It seems to have been "
          "crudely crafted, and rushed through more than one "
          "repair job.");
  SetVendorType(VT_ARMOUR);
  SetMass(750);
    SetArmourClass(ARMOUR_CHAIN);
  SetValue(300);
  SetDamagePoints(600);
  SetMaterial("metal");
  SetArmourType(A_ARMOUR);
  SetWarmth(0);
  SetRepairDifficulty(2);
  SetRepairSkills( ([
    "armour smithing" : 5,
    "metal working"   : 5,
    ]) );
}
