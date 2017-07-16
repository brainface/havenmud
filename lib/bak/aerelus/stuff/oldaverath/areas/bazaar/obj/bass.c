#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("bass");
  SetId( ({"bass"}) );
  SetAdjectives( ({"bass","large"}) );
  SetShort("a large bass");
  SetLong("A nice sized bass with large eyes.");
  SetMass(15);
  SetMealType(MEAL_FOOD);
  SetStrength(30);
  SetMealMessages("You eat a whole bass.", 
                  "$N eats a large bass.");
  }
 
