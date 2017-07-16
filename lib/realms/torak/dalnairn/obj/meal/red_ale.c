//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("ale");
  SetId( ({ "bottle", "ale" }) );
  SetAdjectives( ({ 
    "dalnairi", "red"
  }) );
  SetShort("a bottle of red ale");
  SetLong("A nice bottle of Dalnairi Red Ale.");
  SetMass(20);
  SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
  SetStrength(30);
  SetMealMessages(
    "You drink a wonderful bottle of Dalnairi Red Ale.",
    "$N drinks a wonderful bottle of Dalnairi Red Ale."
  );
  SetEmptyName("bottle");
  SetEmptyShort("an empty bottle of ale");
  SetEmptyLong("It is an empty brown bottle that once held some ale.");
}
