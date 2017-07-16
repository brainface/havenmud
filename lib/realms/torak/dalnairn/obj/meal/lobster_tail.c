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
  SetKeyName("lobster tail");
  SetId( ({ 
    "grilled"
  }) );
  SetAdjectives( ({ 
    "grilled", "lobster"
  }) );
  SetShort("a grilled lobster tail");
  SetLong(
    "This is a grilled tail from a lobster."
  );
  SetMass(10);
  SetMealType(MEAL_FOOD);
  SetStrength(90);
  SetMealMessages(
    "The lobster tail was grilled to perfection!",
    "$N perks up after eating a grilled lobster tail.");
}
