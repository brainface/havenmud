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
  SetKeyName("orange juice");
  SetId( ({ "glass", "juice", }) );
  SetAdjectives( ({ 
    "glass", "of", "orange"
  }) );
  SetShort("a glass of orange juice");
  SetLong("A glass of orange juice.");
  SetMass(20);
  SetMealType(MEAL_DRINK);
  SetStrength(20);
  SetMealMessages(
    "You drink a wonderful glass of orange juice.",
    "$N drinks a wonderful glass of orange juice."
  );
  SetEmptyName("glass");
  SetEmptyShort("an empty glass");
  SetEmptyLong("It is an empty clear glass.");
}
