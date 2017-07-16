#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("mako");
    SetId( ({ "mako","fish" }) );
    SetAdjectives( ({ "shortfin" }) );
    SetShort("a shortfin mako");
    SetLong("This is a shortfin mako, a steel blue tinted shark. The big black eyes stare "
            "blankly into space above the open mouth, full with rows of daggerlike teeth. "
            "It looks like it would make a wonderful meal.");
    SetMass(250);
    SetMealType(MEAL_FOOD);
    SetStrength(60);
  SetValue(500);
    SetMealMessages("It tastes excellent.", "$N eats a shortfin mako.");
}
