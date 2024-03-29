/*    /domains/Ylsrim/meal/stew.c
 *    from the Nightmare V Object Library
 *    created by Descartes of Borg 960302
 */

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("elven stew");
    SetId( ({ "stew" }) );
    SetAdjectives( ({ "elven" }) );
    SetShort("hot elven stew");
    SetLong("This stew is made from the left-overs of other dishes served at "
            "the inn.");
    SetMass(10);
    SetMealType(MEAL_FOOD);
    SetStrength(75);
    SetMealMessages("The stew clears your sinuses!",
		    "$N perks up after eating some elven stew.");
}
