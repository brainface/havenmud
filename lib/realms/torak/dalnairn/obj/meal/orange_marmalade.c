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
  SetKeyName("orange marmalade");
  SetShort("a jar of orange marmalade");
  SetId( ({ 
    "jar", "marmalade" 
  }) );
  SetAdjectives( ({ 
    "glass", "jar", "of", "orange" 
  }) );
  SetLong(
    "This is a glass jar of orange marmalade. "
    "Varying chunks of crushed oranges permeate the jelly. "
  );
  SetMass(5);
  SetMealType(MEAL_FOOD);
  SetStrength(30);
  SetPortions(10);
  SetMealMessages(
    "You eat some orange marmalade from a glass jar.",
    "$N eats some orange marmalade from a glass jar."
  );
  SetEmptyName("jar");
  SetEmptyShort("an empty glass jar");
  SetEmptyLong("It is an empty clear jar that once held some orange marmalade.");
}
