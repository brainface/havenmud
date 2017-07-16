#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("roast rabbit");
    SetId( ({ "rabbit" }) );
    SetAdjectives( ({ "roast" }) );
    SetShort("a small roasted rabbit");
    SetLong("This is a small rabbit that has been lightly seasoned and "
	"roasted over a spit on an open flame.  It is light brown in "
	"color and very warm.");
    SetMass(10);
    SetMealType(MEAL_FOOD);
    SetStrength(65);
    SetMealMessages("The roast rabbit taste very good!",
	"$N gets a rosy glow after eating a roast rabbit.");
}