#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("seabass");
    SetId( ({ "seabass","fish" }) );
    SetAdjectives( ({ "black", "ugly" }) );
    SetShort("a black seabass");
    SetLong("This ugly black seabass has a brownish red color and a blue streak on the "
            "top of it's head. The fins and tail are large and fluttery. "
            "It looks like it would make a decent meal.");
    SetMass(30);
    SetMealType(MEAL_FOOD);
    SetStrength(50);
    SetPortions(2);
    SetValue(60);
    SetMealMessages("It tastes excellent.", "$N eats a black seabass.");
}
