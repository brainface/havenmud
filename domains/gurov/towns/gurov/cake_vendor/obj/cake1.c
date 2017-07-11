//Illura@Haven
//June 2009
#include <lib.h>
#include <meal_types.h>
#include "../cake.h"
inherit LIB_MEAL;
inherit LIB_SMELL;

static void create() {
   meal::create();
   SetKeyName("raspberry cake");
   SetShort("a hunk of raspberry cake");
   SetId( ({ "hunk","cake", }) );
   SetAdjectives( ({ "raspberry" }) );
   SetLong("The moist cake is bursting with the flavor "
           "of sweet, sun-ripened berries, which have "
           "made it pinkish, and golden on the edges.");
   SetMaterial("natural");
   SetMealType(MEAL_FOOD);
   SetStrength(10);
   SetMealMessages("Your mouth is flooded with sweetness.",
                   "$N finishes off a piece of cake.");
   SetSmell("The cake smells of brown sugar and berries.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
