//
// Dalnairn Total Recode
// Torak@Haven 2014-2017
// Oyster Shell
//

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("truffle");
  SetId( ({ "truffle" }) );
  SetAdjectives( ({ "black" }) );
  SetShort("a black truffle");
  SetMass(5);
  SetLong(
    "A truffle is the fruiting body of a subterranean fungus."
  );
  SetMealType(MEAL_FOOD);
  SetStrength(15);
  SetPortions(1);
  SetValue(25);
  SetMealMessages(
    "You eat a black truffle.",
    "$N eats a black truffle.");
}
