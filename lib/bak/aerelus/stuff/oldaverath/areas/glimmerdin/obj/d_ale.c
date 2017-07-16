#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("ale");
    SetId( ({ "bottle", "ale" }) );
    SetAdjectives( ({"dwarven","strong"}) );
    SetShort("a bottle of dwarven ale");
    SetLong("A dark bottle of strong dwarven ale.");
    SetMass(60);
    SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
    SetValue(10);
    SetStrength(15);
    SetMealMessages("Hair grows on your chest as you guzzle the dwarven "
                    "ale.",
		    "$N somehow looks tougher and meaner after drinking a dwarven ale.");
    SetEmptyName("bottle");
    SetEmptyShort("an empty bottle of Dwarven Ale");
    SetEmptyLong("It is an empty brown bottle that once held some ale.");
}
