#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("fish");
    SetId( ({ "cave fish", "blind fish", "blind cave fish" }) );
    SetAdjectives( ({ "small" }) );
    SetShort("a cave fish");
    SetLong("A small blind cave fish.");
    SetMass(15);
    SetMealType(MEAL_FOOD);
    SetStrength(20);
    SetMealMessages("It tastes good in a cold slimy way.", "$N eats a cave fish");
  }
