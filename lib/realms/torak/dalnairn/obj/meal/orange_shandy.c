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
  SetKeyName("orange shandy");
  SetId( ({ "bottle", "shandy", "ale", "juice" }) );
  SetAdjectives( ({ 
    "dalnairi", "orange"
  }) );
  SetShort("a bottle of orange shandy");
  SetLong("A nice bottle of Dalnairi Orange Shandy. "
          "A pleasant blend of orange juice and ale.");
  SetMass(20);
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(20);
  SetMealMessages(
    "You drink a wonderful bottle of Dalnairi Orange Shandy.",
    "$N drinks a wonderful bottle of Dalnairi Orange shandy."
  );
  SetEmptyName("bottle");
  SetEmptyShort("an empty bottle of Dalnairi Orange Shandy");
  SetEmptyLong("It is an empty clear bottle that once held some shandy.");
}
