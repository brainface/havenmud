#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("trout");
  SetShort("a heavy trout");
  SetId( ({ "trout", "fish" }) );
  SetAdjectives( ({ "heavy" }) );
  SetStrength(50);
  SetMass(10);
  SetPortions(3);
  SetLong("This trout is large and would make a decent meal for "
          "almost anyone.");
  SetMealMessages( ({
    "$N eats a trout.",
    "You eat a trout.",
    }) );
  SetMealType(MEAL_FOOD);
  SetValue(20);
}
