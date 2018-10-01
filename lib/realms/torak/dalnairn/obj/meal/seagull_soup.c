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
  SetKeyName("soup");
  SetId( ({ 
    "soup"
  }) );
  SetAdjectives( ({ 
    "creamy", "cream", "of", "seagull"
  }) );
  SetShort("a cream of seagull soup");
  SetLong(
    "This cream of seagull soup is served inside a turtle shell. "
  );
  SetMass(10);
  SetMealType(MEAL_FOOD);
  SetStrength(50);
  SetPortions(3);
  SetMealMessages(
    "The creamy seagull soup is delicious!",
    "$N perks up after eating some creamy seagull soup.");
  SetEmptyName("shell");
  SetEmptyShort("an empty turtle shell");
  SetEmptyLong("It is an empty turtle shell that once held some cooked food.");
}
