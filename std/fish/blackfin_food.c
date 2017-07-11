#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("tuna");
    SetId( ({ "tuna","fish" }) );
    SetAdjectives( ({ "blackfin" }) );
    SetShort("a blackfin tuna");
    SetLong("This is a wide blackfin tuna, with a shining silver belly and a black back. "
            "The flesh just behind the pectoral fins is a rusty orange color. "
            "It looks like it would make a great meal.");
    SetMass(250);
    SetMealType(MEAL_FOOD);
    SetStrength(50);
  SetValue(500);
    SetMealMessages("It tastes excellent.", "$N eats a blackfin tuna.");
}
