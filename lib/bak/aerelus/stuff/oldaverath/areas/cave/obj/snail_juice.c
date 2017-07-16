
// Snail Juice
// Laoise
// May 2001

#include <lib.h>
#include <meal_types.h>
#include <caves.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("juice");
    SetId( ({ "snail juice", "pouch", "juice", "drink" }) );
    SetAdjectives( ({ "snail", "small", "pouch" }) );
    SetShort("a small pouch of snail juice");
    SetLong(
    "A small green pouch containing some snail juice."
    );
    SetMass(10);
    SetMealType(MEAL_DRINK);
    SetStrength(10);
    SetMealMessages("You suck the snail juice from the pouch "
    "and toss the empty pouch aside.",
    "$N sucks the snail juice from a pouch and then discards it.");
}
