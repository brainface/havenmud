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
  SetShort("a %^BOLD%^BLACK%^chitinous black exoskeleton%^RESET%^");
  SetLong(
    "This chitinous exoskeleton was grown "
    "by a thri-kreen.  The black chitinous "
    "casing is sturdy yet lightweight."
  );
  SetValue(5000);
  SetMass(100);
  SetWarmth(0);
  SetDamagePoints(3000);
  SetId( ({
    "suit", "exoskeleton"
  }) );
  SetAdjectives( ({
    "chitinous", "black"
  }) );
  SetMaterials( ({ "natural" }) );
  SetProtectionBonus(ACID, 5);
  SetProtectionBonus(HEAT, 5);
  SetSize(SIZE_VERY_SMALL);
  SetRepairDifficulty(40);
  SetArmourClass(ARMOUR_NATURAL);
}

