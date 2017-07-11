#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("arctic fox stew");
    SetId( ({ "stew" }) );
    SetAdjectives( ({ "arctic","fox" }) );
    SetShort("arctic fox stew");
    SetLong("The thick stew has generous portions of arctic fox garnished "
            "with large chuncks of onion, potatoe, and carrots. The thick "
            "soup has probably been cooking for a few days, for the odorous "
            "spices to cook in.");
    SetMass(13);
    SetMealType(MEAL_FOOD);
    SetStrength(35);
    SetMealMessages("The warm stew warms you from the inside out.",
                    "$N looks warmed by eating arctic fox stew.");
}
