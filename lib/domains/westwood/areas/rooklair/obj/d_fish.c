#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("fish");
  SetId( ({ "fish","dragon" }) );
  SetAdjectives( ({ "dragon" }) );
  SetShort("a dragon fish");
  SetLong("A dragon fish thats looks very tasty.");
  SetMass(100);
  SetMealType(MEAL_FOOD);
  SetStrength(75);
  SetMealMessages("It taste very fishy.", "$N eats a dragon fish.");
}
