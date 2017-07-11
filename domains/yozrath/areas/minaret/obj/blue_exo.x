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
  SetShort("a %^BLUE%^BOLD%^chitinous blue exoskeleton%^RESET%^");
  SetLong(
    "This chitinous exoskeleton was grown "
    "by a thri-kreen.  The blue chitinous "
    "casing is sturdy yet lightweight."
  );
  SetValue(7000);
  SetMass(150);
  SetWarmth(0);
  SetDamagePoints(6000);
  SetId( ({ 
    "suit", "exoskeleton" 
  }) );
  SetAdjectives( ({ 
    "chitinous", "blue"
  }) );
  SetMaterials( ({ "natural" }) );
  SetProtectionBonus(ACID, 10);
  SetProtectionBonus(BLUNT, 5);
  SetProtectionBonus(SLASH, 5);
  SetProtectionBonus(PIERCE, 5);
  SetProtectionBonus(MAGIC, 5);
  SetProtectionBonus(SHOCK, 5);
  SetProtectionBonus(COLD, 5);
  SetProtectionBonus(HEAT, 5);
  SetSize(SIZE_LARGE);
  SetRepairDifficulty(40);
  SetArmourClass(ARMOUR_NATURAL);
}
