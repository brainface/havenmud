// Coded by Zeratul 11-27-99
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("small fish");
  SetShort("a small fish");
  SetId( ({ "small fish", "fish" }) );
  SetAdjectives( ({ "small" }) );
  SetLong("The small fish is about six inches in size. "
     );
  SetMass(10);
  SetMealType(MEAL_FOOD);
  SetStrength(25);
  SetMealMessages("The small fish tastes good.",
     "$N eats a small fish.");
}
