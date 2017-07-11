//Selket@Haven
//2006
#include <lib.h>
inherit LIB_MEAL;
#include <meal_types.h>
#include "../parva.h"

static void create() {
   meal::create();
   SetKeyName("fountain");
   SetId( ({ "fountain" }) );
   SetShort("a fountain");
   SetMealType(MEAL_DRINK);
   SetLong(
    "This fountain is the main source of drinking water "
    "for the citizens of Parva. It is constructed of marble, "
    "and some friendly artisan has carved a seashell design "
    "into the sides.");
   SetPreventGet(
    "The fountain would probably not fit in your pockets.");
   SetStrength(100);
   SetMealMessages( ({ "The water tastes a little salty.",
                   "$N drinks from the fountain." }) );
   SetPortions(-1);
}

