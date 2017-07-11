#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("pipe");
  SetId( ({ "pipe",}) );
  SetAdjectives( ({ "wooden", "wood" }) );
  SetShort("a wooden pipe");
  SetMass(1);
  SetLong("This pipe has been hand carved from a "
          "piece of oak wood. The bowl has a long stem "
          "protruding from it with a wooden filter at the "
          "end. It glimmers from the wax coating in the "
          "light.\n"
          "To use the pipe you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(3);
  SetPortions(4);
  SetValue(4);
  SetMealMessages(
    "You take puff off the wooden pipe. The embers burn softly.",
    "$N puffs on a wooden pipe."
    );
}
