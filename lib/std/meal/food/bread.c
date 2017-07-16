#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("bread");
  SetId( ({ "bread", "loaf"}) );
  SetAdjectives( ({ "small", "loaf", "of" }) );
  SetShort("a small loaf of bread");
  SetMass(1);
  SetLong("This is a rather plain, small loaf of bread.  It looks moderately filling.");
  SetMealType(MEAL_FOOD);
  SetStrength(15);
  SetPortions(8);
  SetMealMessages(
    "You eat a slice of bread.  It's quite filling and tasty.",
    "$N eats a slice of bread.");
}
