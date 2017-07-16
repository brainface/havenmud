/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("fuzzy peach");
    SetId( ({ "peach","fruit" }) );
    SetAdjectives( ({ "fuzzy", "red" }) );
    SetShort("a fuzzy peach");
    SetLong("The fuzz of the peach is almost ticklish.");
    SetMass(3);
    SetValue(5);
    SetMealType(MEAL_FOOD);
    SetStrength(13);
    SetMealMessages("The fuzz feels kind of funny at the first bite.",
		    "$N eats a peach.");
}
