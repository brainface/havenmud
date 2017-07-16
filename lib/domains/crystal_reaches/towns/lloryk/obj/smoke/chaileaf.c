#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("chai");
  SetId( ({ "leaf" }) );
  SetAdjectives( ({ "chai", "leaf" }) );
  SetShort("a chai leaf roll");
  SetMass(1);
  SetLong("This leaf roll has been crafted with natural ingredients. "
          "A dark green leaf has been wrapped around tiny pieces "
          "of chai shreds which has been sealed together into a "
          "roll with honey. The letter \"L\" been burned into the "
          "surface near the end one smokes from.\n"
          "To use the cigarette you must first 'light' it.");
  SetMealType(MEAL_SMOKE);
  SetStrength(15);
  SetPortions(4);
  SetValue(35);
  SetMealMessages(
    "You partake of the gentle wafts of the pine smelling chai roll.",
    "$N puffs on a chai leaf roll.  A faintly pine smell lingers behind."
    );
}
