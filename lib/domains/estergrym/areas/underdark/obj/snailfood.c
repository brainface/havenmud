#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("snail");
    SetId( ({ "snail", "large snail", "aquatic snail" }) );
    SetAdjectives( ({ "large" }) );
    SetShort("a snail");
    SetLong("A large aquatic snail.");
    SetMass(15);
    SetMealType(MEAL_FOOD);
    SetStrength(20);
    SetMealMessages("Slimy, yet satisfying.", "$N eats a large snail.");
  }
