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
    "wood working" : 1,
    "armour smithing" : 1,
    ]) );
  SetMaterial( ({ "wood" }) );
  SetShort("a small wooden shield");
  SetId( ({ "shield", }) );
  SetAdjectives( ({ "wooden", "small" }) );
  SetDamagePoints(1200);
  SetValue(75);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_SHIELD);
  SetMass(175);
  SetLong("This is a small wooden shield.  It might take some pounds "
          "before it breaks, but probably could be cut through easily.");
 }
