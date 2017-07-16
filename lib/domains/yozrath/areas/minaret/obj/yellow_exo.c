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
  SetShort("a chitinous yellow exoskeleton");
  SetLong(
    "This chitinous exoskeleton was grown "
    "by a thri-kreen.  The yellow chitinous "
    "casing is sturdy yet lightweight."
  );
  SetValue(4000);
  SetMass(100);
  SetWarmth(0);
  SetDamagePoints(5000);
  SetId( ({ 
    "suit", "exoskeleton" 
  }) );
  SetAdjectives( ({ 
    "chitinous", "yellow"
  }) );
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(40);
  SetProtectionBonus(ACID, 10);
  SetSize(SIZE_LARGE);
  SetArmourClass(ARMOUR_NATURAL);
}
