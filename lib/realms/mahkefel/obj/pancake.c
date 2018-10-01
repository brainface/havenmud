#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("pancake");
  SetId( ({ "pancake"}) );
  SetAdjectives( ({ "people" }) );
  SetShort("a people pancake");
  SetMass(1);
  SetLong("A pancake! It's MADE OF PEOPLE! Two birds, one delicious and nutritious stone!.");
  SetMealType(MEAL_FOOD|MEAL_CAFFEINE);
  SetStrength(15);
  SetPortions(8);
  SetMealMessages(
    "It tastes like JUSTICE. And SUGAR.");
}

