#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("roll");
  SetId( ({ "roll", "bark roll" }) );
  SetAdjectives( ({ "ground"}) );
  SetShort("a ground bark roll");
  SetMass(2);
  SetLong("This roll is composed of a very dry bark which "
          "has been rolled tightly around lime green powder. "
          "It is around a human index finger in length and "
          "width with small amounts of powder along the "
          "outside wrapping.\n"
          "To use the bark roll you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(5);
  SetPortions(8);
  SetValue(10);
  SetMealMessages(
    "You take a hit off the bark roll, it has a very harsh flavor.",
    "$N takes a drag off the bark roll."
    );
}
