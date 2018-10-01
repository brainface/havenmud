#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("guppy");
  SetShort("a guppy");
  SetStrength(10);
  SetMass(5);
  SetId( ({ "guppy", "fish" }) );
  SetAdjectives( ({}) );
  SetLong("This guppy is a small fish.  It is barely worth eating.");
  SetMealMessages( ({
    "$N eats a guppy.",
    "You eat a guppy.",
    }) );
  SetMealType(MEAL_FOOD);
  SetValue(10);
}
