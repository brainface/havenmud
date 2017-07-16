#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("roll");
  SetId( ({ "leaf", "leaf roll", "roll" }) );
  SetAdjectives( ({ "whember"}) );
  SetShort("a whember leaf roll");
  SetMass(1);
  SetLong("This whember leaf roll is found and crafted "
          "in the town of Baria. An olive-colored leaf "
          "has been wrapped around a brown stem from "
          "a plant. It appears very moist and would burn "
          "slowly if smoked.\n"
          "To use the leaf roll you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(7);
  SetPortions(7);
  SetValue(25);
  SetMealMessages(
    "You take a deep drag on the whember leaf roll, emitting blue smoke.",
    "$N puffs on the leaf roll, emitting blue smoke."
    );
}
