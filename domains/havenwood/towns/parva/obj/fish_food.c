#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("fish");
   SetShort("a small fish");
   SetId( ({ "fish" }) );
   SetAdjectives( ({ "small" }) );
   SetLong("The small fish is green and brown.  It looks edible.");
   SetMass(5);
   SetMealType(MEAL_FOOD);
   SetStrength(5);
   SetMealMessages("The small fish tastes okay.",
                   "$N eats a small fish.");
}
