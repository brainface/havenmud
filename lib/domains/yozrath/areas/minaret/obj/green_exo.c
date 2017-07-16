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
  SetShort("a chitinous green exoskeleton");
  SetLong(
    "This chitinous exoskeleton was grown "
    "by a thri-kreen.  The green chitinous "
    "casing is sturdy yet lightweight."
  );
  SetSize(SIZE_LARGE);
  SetValue(4500);
  SetMass(100);
  SetWarmth(0);
  SetDamagePoints(5000);
  SetId( ({ 
    "suit", "exoskeleton" 
  }) );
  SetAdjectives( ({ 
    "chitinous", "green"
  }) );
  SetMaterials( ({ "natural" }) );
  SetProtectionBonus(ACID, 10);
  SetProtectionBonus(MAGIC, 5);
  SetRepairDifficulty(40);
  SetArmourClass(ARMOUR_NATURAL);
}
