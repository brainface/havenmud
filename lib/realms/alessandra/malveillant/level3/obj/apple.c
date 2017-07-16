#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  
  SetKeyName("apple");
  SetId( ({"apple"}) );
  SetAdjectives( ({"small", "shiny"}) );
  SetShort("a small shiny apple");
  SetLong(
     "This is a small shiny apple, it doesn't look like it would be very"
     "filling."
     );
  SetMealType(MEAL_FOOD);
  SetStrength(5);
  SetPortions(2);
  SetMass(3);
  SetMealMessages(
     "You bite into an apple.",
     "$N bites into an apple.",
     );

}
