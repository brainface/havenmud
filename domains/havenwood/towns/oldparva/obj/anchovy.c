#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("anchovy");
   SetShort("a small raw anchovy");
   SetId( ({ "anchovy" }) );
   SetAdjectives( ({ "small","raw" }) );
   SetLong("The anchovy is small and blue.  It's one of the "
           "smaller types of fish, and also one of the "
           "saltiest.");
   SetMass(5);
   SetStrength(5);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N chew up a raw anchovy.  Wow!  Salty!",
                   "$N chews up a raw anchovy.");
   if(!random(37)) {
      SetMealType(MEAL_FOOD|MEAL_POISON);
      SetStrength(2);
      SetMealMessages("$N chew up a raw anchovy, and feel a "
                      "little sick afterwords.","$N turns "
                      "slightly green while eating a "
                      "raw anchovy.");
   }
}
