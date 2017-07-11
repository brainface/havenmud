#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("cheese wedge");
   SetShort("a wedge of cheddar cheese");
   SetId( ({ "wedge", "cheese" }) );
   SetAdjectives( ({ "wedge", "of", "cheddar", "cheese" }) );
   SetLong("This thick wedge of cheddar cheese is a basic white in "
           "color.");
   SetAdjectives( ({ "cheddar" }) );
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(10);
   SetPortions(6);
   SetMealMessages("You eat some sharp cheddar cheese.",
                   "$N eats some cheese.");
}
