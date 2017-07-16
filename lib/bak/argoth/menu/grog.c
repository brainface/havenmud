#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
static void create() {
    meal::create();
    SetKeyName("grog");
    SetId( ({ "orkish grog", "grog" }) );
    SetShort("a cup of orkish grog");
    SetLong("This thick, green liquid looks as sickening as any drink that "
    "has ever been conceived.  It takes firm resolve to be able to down it.");
    SetMass(20);
    SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
    SetStrength(45);
    SetMealMessages("You slurp up the thick, chunky orkish grog.  It tastes "
    "disgusting.",  "$N chokes down an entire mug of grog with ghastly "
    "slurping noises.");
}
