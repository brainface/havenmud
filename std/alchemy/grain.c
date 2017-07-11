#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
	::create();
	SetKeyName("grain");
	SetShort("a handful of grain");
	SetId( ({ "grain" }) );
	SetLong("This is a handful of grain.");
	SetMealType(MEAL_FOOD);
	SetStrength(5);
}
