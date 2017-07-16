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
   SetLong("A dead, slimy fish.");
   SetMass(15);
   SetMealType(MEAL_FOOD);
   SetStrength(25);
   SetMealMessages("It slides down easily.", "$N eats a small fish.");
}
