#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("steak");
  SetId( ({ "steak" }) );
  SetAdjectives( ({ "large", "juicy" }) );
  SetShort("a large, juicy steak");
  SetMass(20);
  SetLong("This is a large, juicy steak.  It is well done.");
  SetMealType(MEAL_FOOD);
  SetPortions(4);
  SetStrength(100);
  SetMealMessages("You eat some of the large, juicy steak.  It is quite filling.",
                  "$N eats some of the large, juicy steak.");
}

