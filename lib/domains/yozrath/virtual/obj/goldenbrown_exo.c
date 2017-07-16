// Torak 8/12/2013

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("armour");
  SetArmourType(A_BODY_ARMOUR);
  SetShort("a golden brown chitinous exoskeleton");
  SetLong(
    "This chitinous exoskeleton was grown "
    "by a thri-kreen. The casing is sturdy "
    "yet lightweight and a golden brown color."
  );
  SetValue(3000);
  SetMass(90);
  SetWarmth(0);
  SetDamagePoints(3000);
  SetId( ({ 
    "suit", "exoskeleton" 
  }) );
  SetAdjectives( ({ 
    "chitinous",
  }) );
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(30);
  SetProtectionBonus(ACID, 10);
  SetArmourClass(ARMOUR_NATURAL);
}
