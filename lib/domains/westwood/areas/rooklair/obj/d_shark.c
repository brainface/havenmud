#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("shark");
  SetId( ({ "shark","dragon" }) );
  SetAdjectives( ({ "dragon" }) );
  SetShort("a dragon shark");
  SetLong("A dragon shark who once looked brutal, now looks like "
    "lunch.");
  SetMass(100);
  SetMealType(MEAL_FOOD);
  SetStrength(150);
  SetMealMessages("It is very filling.", "$N eats a dragon shark.");
}
