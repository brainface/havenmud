#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("catfish");
  SetShort("a catfish");
  SetStrength(35);
  SetPortions(4);
  SetMass(40);
  SetId( ({ "catfish", "fish" }) );
  SetAdjectives( ({ }) );
  SetLong(
    "This is a variety of catfish native to the Itro River in Xandria."
    "It looks tasty."
    );
  SetMealMessages( ({
    "$N eats some catfish.",
    "You eat some catfish.",
    }) );
  SetMealType(MEAL_FOOD);
  SetValue(30);
}
