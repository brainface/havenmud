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
  SetKeyName("orange sangria");
  SetId( ({ "bottle", "sangria" }) );
  SetAdjectives( ({ 
    "dalnairi", "orange"
  }) );
  SetShort("a bottle of orange sangria");
  SetLong(
    "A nice bottle of Dalnairi Orange Sangria. "
    "A pleasant blend of brandy and red ale with "
    "crushed oranges."
  );
  SetMass(20);
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(40);
  SetMealMessages(
    "You drink a wonderful bottle of Dalnairi Orange Shandy.",
    "$N drinks a wonderful bottle of Dalnairi Orange shandy."
  );
  SetEmptyName("bottle");
  SetEmptyShort("an empty bottle of Dalnairi Orange Sangria");
  SetEmptyLong("It is an empty clear bottle that once held some sangria.");
}
