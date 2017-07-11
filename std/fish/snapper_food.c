#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("snapper");
    SetId( ({ "snapper","fish" }) );
    SetAdjectives( ({ "yellowtail" }) );
    SetShort("a yellowtail snapper");
    SetLong("This is a fat yellowtail snapper, a mottled gray and white fish speckled with "
            "golden spots. A streak of gold runs across its body from nose to golden tail. "
            "It looks like it would make a great meal.");
    SetMass(50);
    SetMealType(MEAL_FOOD);
    SetStrength(20);
  SetValue(100);
    SetMealMessages("It tastes excellent.", "$N eats a yellowtail snapper.");
}
