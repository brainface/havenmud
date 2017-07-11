// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
 
static void create() {
   meal::create();
   SetKeyName("fish");
   SetId( ({ "small fish", "fish" }) );
   SetAdjectives( ({ "small" }) );
   SetShort("a small fish");
   SetLong("The small fish is slimy, and, conveniently for any interested "
	"in carrying it around or eating it, dead.");
   SetMass(15);
   SetMealType(MEAL_FOOD);
   SetStrength(10);
   SetMealMessages("It slides down easily.", "$N eats a small fish.");
}