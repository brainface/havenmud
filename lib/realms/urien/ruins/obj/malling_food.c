#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("malling");
  SetShort("a malling");
  SetStrength(20);
  SetMass(17);
  SetId( ({ "malling", "fish" }) );
  SetAdjectives( ({"red"}) );
  SetLong("This malling is a red coloured fish with two "
          "fins on its tail. It has the shape of a carrot "
          "with dark beady eyes which have a milky white "
          "color to them. Small bones protrude from its "
          "body which ooze a dark black ink.");
  SetMealMessages( ({
    "$N eats a malling, small bones crunching can be heard.",
    "You eat a malling, the bones crunching proves difficult. The "
    "ink from that fish tastes poisonous.",
    }) );
  SetMealType(MEAL_FOOD|MEAL_POISON);
  SetValue(10);
}
