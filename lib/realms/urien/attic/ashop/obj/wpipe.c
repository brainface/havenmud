#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("pipe");
  SetId( ({ "pipe", "wooden" }) );
  SetAdjectives( ({ "carved"}) );
  SetShort("a carved wooden pipe");
  SetMass(2);
  SetLong("This pipe has been filled with a moist, shredded "
          "tobacco. The bowl of the pipe has been hand-carved "
          "by a miraculous craftsman. It is near flawless. A "
          "stem protrudes from the bowl where the user "
          "puffs on the tobacco when lit.\n"
          "To use the pipe you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(12);
  SetPortions(30);
  SetValue(100);
  SetMealMessages(
    "You take puffs on the carved wooden pipe, blowing smoke rings.",
    "$N blows smoke rings from the carved wooden pipe."
    );
}
