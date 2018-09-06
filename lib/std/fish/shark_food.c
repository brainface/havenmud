#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("shark");
  SetShort("a blue shark");
  SetStrength(100);
  SetPortions(3);
  SetMass(100);
  SetId( ({ "shark", "fish" }) );
  SetAdjectives( ({}) );
  SetLong("It is a huge, long fish with razor sharp teeth and a carnivorous appetite.");
  SetMealMessages( ({
    "$N eats a blue shark.",
    "You eat a blue shark.",
    }) );
  SetMealType(MEAL_FOOD);
  SetValue(200);
}
