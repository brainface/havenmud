#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("date");
  SetId( ({ "date" }) );
  SetAdjectives( ({ "sweet" }) );
  SetShort("a sweet date");
  SetMass(1);
  SetLong("The date is a small brown fruit with a thin, "
    "prunish skin.  The juicy fruit looks delicious."
  );
  SetMealType(MEAL_FOOD);
  SetStrength(10);
  SetPortions(1);
  SetMealMessages(
    "You eat a juicy date and spit out the seed.",
    "$N eats a date and spits out the seed.");
}
