/* Added SetMass to get xp from farming
	 Zalbar July 08
 */


#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_COMBINE;

static void create() {
	::create();
	SetKeyName("sugar");
	SetShort("a handful of sugar");
	SetId( ({ "sugar" }) );
	SetLong("This is a handful of sugar.");
	SetStrength(5);
	SetMealType(MEAL_FOOD|MEAL_CAFFEINE);
	SetMass(1);
}
