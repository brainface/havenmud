#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("pipe");
  SetId( ({ "pipe", "corn" }) );
  SetAdjectives( ({ "cob"}) );
  SetShort("a corn cob pipe");
  SetMass(2);
  SetLong("An ear of corn has been carved into a pipe, "
          "forming the bowl which holds flaked tobacco. "
          "A corn stem protrudes from the bowl with a "
          "deep redwood filter. This would make a great gift "
          "to any sailor or marine for any occasion.\n"
          "To use the pipe you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(10);
  SetPortions(30);
  SetValue(80);
  SetMealMessages(
    "You inhale the corn cob pipe, releasing a massive cloud.",
    "$N inhales the corn cob pipe, releasing a massive cloud of smoke."
    );
}
