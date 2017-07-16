#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("flask");
   SetShort("a water flask");
   SetId( ({ "bottle","water","flask" }) );
   SetAdjectives( ({ "water","quart-sized" }) );
   SetLong("The flask is about half-full of crystal clear water.  It "
           "is quart-sized.");
   SetMass(35);
   SetMealType(MEAL_DRINK);
   SetStrength(40);
   SetMealMessages("Drinking all the water from the bottle makes your "
                  "stomach swish.","$N drinks from a water flask.");
   SetEmptyName("water flask");
   SetEmptyShort("a water flask");
   SetEmptyLong("The flask is quart-sized.  It is empty.");
}
