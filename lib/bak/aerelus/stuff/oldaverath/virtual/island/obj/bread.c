#include <lib.h>
#include <meal_types.h>
#include <domains.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("bread");
    SetId( ({ "roll", "bread", "roll of bread" }) );
    SetAdjectives( ({ "warm" }) );
    SetShort("a roll of warm bread");
    SetLong("This roll of bread is still warm, fresh right out of the oven. ");
    SetMass(5);
    SetMealType(MEAL_FOOD);
    SetStrength(35);
    SetMealMessages("It tastes excellent.", "$N scarfs down a roll of bread.");
}
