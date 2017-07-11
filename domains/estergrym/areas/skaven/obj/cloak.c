#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include "../skaven.h"
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("cloak");
  SetShort("a dull crimson cloak");
  SetId( ({ "cloak" }) );
  SetAdjectives( ({ "crimson", "dull" }) );
  SetLong("This cloak is ragged and holed in many places. "  
          "The edges of the cloak have been double-stitched "
          "additional durability.  A strange black rune has "
          "been painted across the back of the cloak.");
  SetMass(40);
  SetValue(10);
  SetDamagePoints(80);
  SetProperty("multiples", 1);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetWarmth(15);
  SetRepairSkills( (["textile working" : 1,]) );
  SetRepairDifficulty(1);  
  SetArmourType(A_CLOAK);
}
