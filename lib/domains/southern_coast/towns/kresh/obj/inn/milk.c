#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("fermented mare's milk");
  SetShort("a skin of fermented mare's milk");
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetStrength(20);
  SetPortions(10);
  SetId( ({ "skin", "milk" }) );
  SetAdjectives( ({ "fermented", "mare's", "mare" }) );
  SetLong(
    "This skin contains fermented mare's milk, a staple of the "
    "diet for the Goblin Horde."
    );
  SetMealMessages( ({
    "You drink from a skin of fermented mare's milk.",
    "$N drinks from a skin of fermented mare's milk.",
  }) );
}
