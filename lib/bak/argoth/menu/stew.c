#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
static void create() {
    meal::create();
    SetKeyName("stew");
    SetId( ({ "dwarf's head stew", "stew" }) );
    SetShort("a bowl of dwarf's head stew");
    SetLong("This stew is made of ground up dwarves' heads.  Looks appetizing.");
    SetMass(40);
    SetMealType(MEAL_FOOD);
    SetStrength(20);
    SetMealMessages("The dwarf's head stew is piping hot and delicious.", "$N gobbles up a bowl of dwarf's head stew.");
}
