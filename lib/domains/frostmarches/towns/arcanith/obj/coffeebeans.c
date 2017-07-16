#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("beans");
  SetId( ({ "coffee","handful","beans"}) );
  SetAdjectives( ({ "handful","of","unground","coffee" }) );
  SetShort("a handful of unground coffee beans");
  SetMass(1);
  SetLong("A few dozen dark coffee beans, with a fragrant aroma.");
  SetMealType(MEAL_FOOD|MEAL_CAFFEINE);
  SetStrength(15);
  SetPortions(8);
  SetMealMessages(
    "It seems there should be some easier way to do this, you think, as your teeth grind "
    "painfully on the unprepared beans.");
}

