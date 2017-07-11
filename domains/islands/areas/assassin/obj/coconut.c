#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("coconut");
  SetId( ({ "coconut", "coconut_fruit" }) );
  SetAdjectives( ({ "ripe" }) );
  SetShort("a ripe coconut");
  SetPortions(3);
  SetLong("This brown, husky object is a coconut.  It appears to have fallen off "
          "a tree.");
  SetStrength(10);
  SetMealType(MEAL_FOOD);
  SetMealMessages( ({
    "You eat a chunk of coconut.",
    "$N eats a chunk of coconut.",
  }) );
}
