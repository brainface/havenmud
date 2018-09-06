#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("mackerel");
    SetId( ({ "mackerel","fish" }) );
    SetAdjectives( ({ "cero" }) );
    SetShort("a cero mackerel");
    SetLong("This is a cero mackerel, a slim silvery fish stippled with goldenrod spots. "
            "The spiky fins and tail are a dark charcoal color. It looks like it would "
            "make a decent meal.");
    SetMass(36);
    SetMealType(MEAL_FOOD);
    SetStrength(50);
    SetValue(72);
    SetMealMessages("It tastes excellent.", "$N eats a cero mackerel.");
}
