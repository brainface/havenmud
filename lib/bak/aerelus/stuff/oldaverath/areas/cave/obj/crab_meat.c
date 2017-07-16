
// Crab Meat
// Laoise
// May 2001

#include <lib.h>
#include <meal_types.h>
#include <caves.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("meat");
    SetId( ({"meat", "food"}) );
    SetAdjectives( ({ "crab", "meat", "piece" }) );
    SetShort("a piece of crab meat");
    SetLong(
    "A small piece of crab meat from inside a crab's shell."
    );
    SetMass(10);
    SetMealType(MEAL_FOOD);
    SetStrength(10);
    SetMealMessages("You nibble on a small piece of crab meat.",
    "$N eats a small piece of crab meat.");
}
