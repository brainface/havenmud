#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("prawn");
   SetShort("a pink prawn");
   SetId( ({ "prawn" }) );
   SetAdjectives( ({ "pink" }) );
   SetLong("Two night-black button-eyes peer out from the large "
           "head attached to the edible part of the prawn.  "
           "The prawn is pink and about medium size.");
   SetMass(5);
   SetStrength(8);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N chew up a raw prawn!",
                   "$N chews up a raw prawn.");
   if(!random(27)) {
      SetMealType(MEAL_FOOD|MEAL_POISON);
      SetStrength(1);
      SetMealMessages("$N chew up a raw prawn, and feel a "
                      "little sick afterwords.","$N turns "
                      "slightly green while eating a "
                      "raw prawn.");
   }
}
