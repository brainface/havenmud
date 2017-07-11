#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("pomegranate");
  SetId( ({ "pomegranate" }) );
  SetAdjectives( ({ "red" }) );
  SetShort("a red pomegranate");
  SetMass(10);
  SetLong("The pomegranate is a large round red berry "
    "filled with edible anils while the skin is topped "
    "by a beautiful crown.");
  SetMealType(MEAL_FOOD);
  SetStrength(10);
  SetPortions(3);
  SetMealMessages(
    "You eat some arils from the pomegrante.",
    "$N eats some arils from a pomegrante.");
}
