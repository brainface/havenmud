#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("kraken");
    SetId( ({ "small kraken", "kraken" }) );
    SetShort("a small Kraken");
    SetLong("A small squid like creature that lives in dark, fresh water.");
    SetMass(100);
    SetMealType(MEAL_FOOD);
    SetStrength(40);
    SetMealMessages("It is very rubbery.", "$N eats a small kraken.");
}
