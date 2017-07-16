//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>

#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("orange");
  SetId( ({ "orange" }) );
  SetAdjectives( ({ "sweet" }) );
  SetShort("a sweet orange");
  SetMass(15);
  SetLong(
    "The round orange is fleshy and sweet."
  );
  SetMealType(MEAL_FOOD);
  SetStrength(10);
  SetPortions(10);
  SetMealMessages(
    "You eat a slice of orange.",
    "$N eats a slice of orange.");
}
