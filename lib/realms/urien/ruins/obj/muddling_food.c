#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("muddling");
  SetShort("a muddling");
  SetStrength(12);
  SetMass(4);
  SetId( ({ "muddling", "fish" }) );
  SetAdjectives( ({}) );
  SetLong("The muddling is a dark brown fish that is "
          "very tiny in size. It appears to be a malnourished "
          "little fish with dark spots that scatter down his "
          "backside. It only has one fin along the top of its "
          "head and both eyes are milky white.");
  SetMealMessages( ({
    "$N swallows an entire muddling fish.",
    "You eat an entire muddling fish whole.",
    }) );
  SetMealType(MEAL_FOOD);
  SetValue(10);
}
