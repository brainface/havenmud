/* added SetMass to get xp from farming
	 Zalbar July 08
 */


#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_COMBINE;

static void create() {
   meal::create();
	SetKeyName("grain");
	SetShort("a handful of grain");
	SetId( ({ "grain" }) );
	SetLong("This is a handful of grain.");
	SetMealType(MEAL_FOOD);
	SetStrength(5);
	SetMass(1);
}
