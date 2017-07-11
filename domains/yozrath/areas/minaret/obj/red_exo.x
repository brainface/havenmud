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
  SetShort("a %^RED%^chitinous red exoskeleton%^RESET%^");
  SetLong(
    "This chitinous exoskeleton was grown "
    "by a thri-kreen.  The red chitinous "
    "casing is sturdy yet lightweight."
  );
  SetValue(5000);
  SetMass(100);
  SetWarmth(0);
  SetDamagePoints(5000);
  SetId( ({ 
    "suit", "exoskeleton" 
  }) );
  SetAdjectives( ({ 
    "chitinous", "red"
  }) );
  SetMaterials( ({ "natural" }) );
  SetProtectionBonus(ACID, 10);
  SetProtectionBonus(BLUNT, 5);
  SetProtectionBonus(SLASH, 5);
  SetProtectionBonus(PIERCE, 5);
  SetSize(SIZE_LARGE);
  SetRepairDifficulty(40);
  SetArmourClass(ARMOUR_NATURAL);
}
