/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("plum");
    SetId( ({ "plum","fruit" }) );
    SetAdjectives( ({ "purple" }) );
    SetShort("a plum");
    SetLong("The purple plum is just approaching ripeness.");
    SetMass(3);
    SetValue(5);
    SetMealType(MEAL_FOOD);
    SetStrength(13);
    SetMealMessages("Mmmmm, sour and sweet at the same time.",
		    "$N makes a face after biting into a plum.");
}
