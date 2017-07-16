/*
 * Coded by Godel@Haven
 * 7 February 1998
 */

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("small orange");
    SetId( ({ "orange","fruit" }) );
    SetAdjectives( ({ "small", "bright" }) );
    SetShort("a small orange");
    SetLong("Tiny bumps cover the bright fruit.");
    SetMass(3);
    SetValue(5);
    SetMealType(MEAL_FOOD);
    SetStrength(13);
    SetMealMessages("Juice dribbles down your chin.",
		    "$N chomps into a tasty looking orange.");
}
