#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("swordfish");
    SetId( ({ "swordfish","fish" }) );
    SetShort("a swordfish");
    SetLong("This dark gray swordfish has a broad body and a dirty colored belly, "
            "but the most prominent feature about the fish is the long prong on its "
            "snout, designed for making kabobs out of its prey. "
            "It looks like it would make a decent meal.");
    SetMass(350);
    SetMealType(MEAL_FOOD);
    SetStrength(80);
    SetPortions(2);
    SetValue(700);
    SetMealMessages("It tastes excellent.", "$N eats a swordfish.");
}
