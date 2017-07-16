#include <lib.h>
#include <meal_types.h>
#include <domains.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("mutton stew");
    SetId( ({ "stew" }) );
    SetAdjectives( ({ "mutton" }) );
    SetShort("some hot mutton stew");
    SetLong("This hot mutton stew is thick with broth and "
            "chunks of greasy mutton. Mmm mmm good.");
    SetMass(10);
    SetMealType(MEAL_FOOD);
    SetStrength(5);
    SetMealMessages("The stew sits in your stomach like a lead weight.",
                "$N lets out a belch after slurping down the stew.");
}
