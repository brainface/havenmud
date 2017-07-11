/*    /domains/Ylsrim/meal/shark.c
 *    from the Nightmare V Object Library
 *    created by Descartes of Borg 960302
 */

#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("guppy");
    SetId( ({ "guppy","fish" }) );
    SetAdjectives( ({ "little" }) );
    SetShort("a little guppy");
    SetLong("A little guppy who once looked happy, now looks yummy.");
    SetMass(20);
    SetMealType(MEAL_FOOD);
    SetStrength(30);
    SetMealMessages("It tastes excellent.", "$N eats a little guppy.");
}
