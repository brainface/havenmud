#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("roast mutton");
    SetId( ({ "mutton" }) );
    SetAdjectives( ({ "roast","juicy" }) );
    SetShort("hot roast mutton");
    SetLong("The rarely cooked meat is still steaming from the fire where it was "
            "cooked. It looks filling and delicious.");
    SetMass(13);
    SetMealType(MEAL_FOOD);
    SetStrength(55);
    SetMealMessages("The juices from the roast mutton run down your chin.",
                    "$N looks more satisfied after eating roast mutton.");
}
