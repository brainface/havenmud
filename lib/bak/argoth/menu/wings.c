#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
    static void create() {
    meal::create();
    SetKeyName("sprite wings");
    SetId( ({ "sprite wings", "wings" }) );
    SetShort("sprite wings");
    SetLong("These are the wings from a sprite, lightly toasted and served "
    "in a thick sauce.");
    SetMass(20);
    SetMealType(MEAL_FOOD);
    SetStrength(10);
    SetMealMessages("You chomp down on the sprite wings.", "$N rips the meat "
    "off of $P pair of sprite wings.");
}
