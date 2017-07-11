//June 2009
#include <lib.h>
#include <meal_types.h>
#include "../cake.h"
inherit LIB_MEAL;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("carrot cake");
   SetShort("a suspect piece of carrot cake");
   SetId( ({ "cake", "piece", }) );
   SetAdjectives( ({ "suspect", "carrot" }) );
   SetLong("The spicy brown cake is covered with creamy "
           "sweet frosting, studded with nuts. Strangely, "
           "the shreds of carrot within are glowing.");
   SetMass(1);
   SetMaterial("natural");
   SetMealType(MEAL_FOOD);
   SetStrength(10);
   SetMealMessages("With each bite of the cake, your eyes seem to open up wider.",
                   "$N finishes off a piece of cake.");
   SetSmell("The carrot cake smells healthful and tasty.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
