#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_BAIT_WITH;

static void create() {
  ::create();
  SetKeyName("guppy");
  SetShort("a guppy");
  SetStrength(10);
  SetMass(5);
  SetId( ({ "guppy", "fish" }) );
  SetAdjectives( ({}) );
  SetLong("This guppy is a small fish.  It is barely worth eating, but may be "
    "tempting to a larger fish. <help bait>");
  SetMealMessages( ({
    "$N eats a guppy.",
    "You eat a guppy.",
    }) );
  SetMealType(MEAL_FOOD);
  SetValue(10);
  SetBaitStrength(5);
  SetMaterial( ({ "natural" }) );
}

