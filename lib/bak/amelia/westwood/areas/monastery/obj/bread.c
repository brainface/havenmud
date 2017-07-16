#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("fresh bread loaf");
   SetShort("a fresh bread loaf");
   SetId( ({ "loaf","bread","bread loaf" }) );
   SetAdjectives( ({ "loaf" }) );
   SetLong("Steam rises from the fresh bread, showing how short "
           "a time its been since it was taken out of the oven.");
   SetMass(5);
   SetStrength(48);
   SetMealType(MEAL_FOOD);
   SetMealMessages("The bread almost burns your mouth.",
                   "$N eats some fresh bread.");
}