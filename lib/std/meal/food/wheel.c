#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
 
static void create() {
   meal::create();
   SetKeyName("cheese wheel");
   SetShort("a wheel of harvarti cheese");
   SetId( ({ "cheese", "wheel", }) );
   SetLong("This medium-sized wheel of harvarti cheese is a basic white in "
           "color.");
   SetAdjectives( ({ "harvarti", "cheese", "wheel", "of" }) );
   SetMass(20);
   SetMealType(MEAL_FOOD);
   SetStrength(30);
   SetPortions(6);
   SetMealMessages("You eat some of the soft harvarti cheese.",
                   "$N eats some cheese.");
}
