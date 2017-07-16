// 
// Dalnairn Total Recode
// Torak@Haven 2014-2017
// Restaurant Foods
//

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("steak filet");
  SetId( ({ 
    "steak", "filet", "steak filet"
  }) );
  SetAdjectives( ({ 
    "grilled", "wild", "boar", "steak"
  }) );
  SetShort("a grilled wild boar steak filet");
  SetLong(
    "This is a grilled steak from a wild boar."
  );
  SetMass(15);
  SetMealType(MEAL_FOOD);
  SetStrength(115);
  SetMealMessages(
    "The filet was grilled to perfection!",
    "$N perks up after eating a grilled steak filet.");
}
