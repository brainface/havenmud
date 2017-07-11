#include <lib.h>
#include <meal_types.h>
#include "parva.h"
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("lomi-lomi");
   SetShort("a plate of lomi-lomi");
   SetId( ({ "plate","lomi-lomi" }) );
   SetAdjectives( ({ "plate of" }) );
   SetLong("A variety of raw fish sliced in thin strips lie on this "
           "plate.  None of them appear to be cooked.  A "
           "tomato and lemon juice sauce covers the fish up; "
           "the fish appear to have been soaked in it.");
   SetMass(25);
   SetStrength(28);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N eat a plate of lomi-lomi.",
                   "$N eats a plate of lomi-lomi.");
   SetEmptyItem(P_OBJ + "/plate");
   if(!random(70)) {
      SetMealType(MEAL_FOOD|MEAL_POISON);
      SetStrength(8);
      SetMealMessages("$N eat a plate of lomi-lomi and feel sick.",
                     "$N eats a plate of lomi-lomi and turns "
                     "slightly green.");
   }
}
