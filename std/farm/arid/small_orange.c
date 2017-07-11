// straight up copy of yozrath date, would also complete the quest.
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("orange");
  SetId( ({ "orange" }) );
  SetAdjectives( ({ "small" }) );
  SetShort("a small orange");
  SetPortions(2);
  SetLong("This tiny, somewhat withered orange looks like it grew "
    "somewhere without a surplus of water. It still looks juicy "
    "enough, though.");
  SetStrength(20);
  SetMealType(MEAL_FOOD);
  SetMealMessages( ({
    "You bites into a juicy orange half.",
    "$N bites into a juicy orange half.",
  }) );
}


