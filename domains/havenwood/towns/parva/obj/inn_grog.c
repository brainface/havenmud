#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("grog");
   SetShort("a mug of grog");
   SetId( ({ "mug","grog" }) );
   SetAdjectives( ({ "mug of", }) );
   SetLong("The grog is in a dark brown mug.  It doesn't appear "
           "to be flat or unappetizing to a normal beer drinker.");
   SetMass(15);
   SetStrength(25);
   SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
   SetMealMessages("$N gulp down the mug of grog.",
                   "$N drinks a mug of grog.");
}
