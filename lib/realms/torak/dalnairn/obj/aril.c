//
// Dalnairn Total Recode
// Torak@Haven 2014 - 2017
// 

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("aril");
  SetId( ({ "aril" }) );
  SetAdjectives( ({ "red" }) );
  SetShort("a red aril");
  SetMass(1);
  SetLong("This red aril has a fleshy outgrowth "
    "that covers the inner seed.");
   SetMealType(MEAL_POISON|MEAL_FOOD);
  SetStrength(5);
  SetPortions(1);
  SetMealMessages(
    "You eat a red aril.",
    "$N eats a red aril.");
}
