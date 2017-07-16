#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("coffeecake");
  SetId( ({ "cake", "coffeecake"}) );
  SetAdjectives( ({ "small", "slice", "of", "coffee" }) );
  SetShort("a small slice of coffeecake");
  SetMass(1);
  SetLong("This is a rather tasty slice of coffeecake "
          "from the Twitchy Nymph. It looks moderately filling.");
  SetMealType(MEAL_FOOD);
  SetStrength(45);
  SetMealMessages(
    "You eat a slice of cake.  It's quite filling and tasty.",
    "$N eats a slice of cake.");
}
