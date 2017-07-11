#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("tuna");
   SetShort("a tuna fish");
   SetId( ({ "fish","tuna" }) );
   SetAdjectives( ({ "fish","tuna" }) );
   SetLong("The tuna fish is nicely sized.  It's blue all "
           "over, with the darkest blue on top and the lightest "
           "blue on its belly.");
   SetMass(28);
   SetStrength(45);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N chew up a raw tuna fish.  It tastes SALTY!",
                   "$N chews up a raw tuna fish.");
   if(!random(40)) {
      SetMealType(MEAL_FOOD|MEAL_POISON);
      SetStrength(1);
      SetMealMessages("$N chew up a raw tuna fish, and feel a "
                      "little sick afterwords.","$N turns "
                      "slightly green while eating a "
                      "raw tuna fish.");
   }
}
