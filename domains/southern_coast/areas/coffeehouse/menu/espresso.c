#include <lib.h>
#include <meal_types.h>
void NukeMe();
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("espresso");
  SetShort("a tiny mug of espresso");
  SetId( ({ "mug", "espresso" }) );
  SetAdjectives( ({ "mug", "of", "tiny" }) );
  SetMass(5);
  SetLong(
    "This tiny mug seems to hold a thin brownish-black liquid. "
    "The steamy-warm mug gives off a positive hint of energy."
    );
  SetMealType(MEAL_DRINK|MEAL_CAFFEINE);
  SetStrength(50);
  SetMealMessages(
    "You slurp an espresso.",
    "$N slurps an espresso."
    );
}
