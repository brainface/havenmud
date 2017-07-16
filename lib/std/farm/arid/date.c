
// straight up copy of yozrath date, would also complete the quest.
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("date");
  SetId( ({ "date", "date_fruit" }) );
  SetAdjectives( ({ "palm" }) );
  SetShort("a palm date");
  SetPortions(1);
  SetLong("This small fruit is a date.  It appears to have fallen off "
          "a palm tree.");
  SetStrength(10);
  SetMealType(MEAL_FOOD);
  SetMealMessages( ({
    "You eat a small date.",
    "$N eats a small date.",
  }) );
}


