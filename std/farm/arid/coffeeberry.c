// straight up copy of yozrath date, would also complete the quest.
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("coffeeberry");
  SetId( ({ "nut", "coffeeberry" }) );
  SetAdjectives( ({ "coffee", "coffeeberry" }) );
  SetShort("a coffeeberry");
  SetPortions(1);
  SetLong("This thumbnail sized nut is a coffeeberry, known to grown in "
    "desert climes and prized for its oil. Chewing it may be less than " 
    "productive.");
  SetStrength(10);
  SetMealType(MEAL_FOOD);
  SetMealMessages( ({
    "You eat a crunchy nut.",
    "$N eats a crunchy nut.",
  }) );
}


