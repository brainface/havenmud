#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("shield");
  SetRepairDifficulty(10);
  SetRepairSkills( ([
    "metal working" : 1,
    "armour smithing" : 1,
    ]) );
  SetMaterial( ({ "wood" }) );
  SetShort("a small wooden shield");
  SetId( ({ "shield", "wooden shield" }) );
  SetAdjectives( ({ "wooden", "small" }) );
  // SetProtection(BLUNT, 10);
  // SetProtection(SLASH, 6);
  // SetProtection(PIERCE, 4);
  SetDamagePoints(400);
  SetValue(75);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_SHIELD);
  SetMass(175);
  SetLong("This is a small wooden shield.  It might take some pounds "
          "before it breaks, but probably could be cut through easily.");
 }
