/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("red apple");
    SetId( ({ "apple","fruit" }) );
    SetAdjectives( ({ "shiny", "red" }) );
    SetShort("a red apple");
    SetLong("Light gleams off the shiny red apple.");
    SetMass(3);
    SetValue(5);
    SetMealType(MEAL_FOOD);
    SetStrength(13);
    SetMealMessages("The apple responds with a loud - CRUNCH.",
		    "$N looks startled by the loud CRUNCH of an apple.");
}
