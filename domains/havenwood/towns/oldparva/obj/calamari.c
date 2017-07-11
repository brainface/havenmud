#include <lib.h>
#include <meal_types.h>
#include "parva.h"
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("calamari");
   SetShort("a plate of calamari");
   SetId( ({ "plate","calamari" }) );
   SetAdjectives( ({ "plate of" }) );
   SetLong("The calamari is squid rings with a spicey seafood "
           "tomato sauce.  There are about 15 rings on the plate.");
   SetMass(25);
   SetStrength(45);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N eat a plate of calamari.  The squid is a "
                   "little rubbery, but good.",
                   "$N eats a plate of calamari.");
   SetEmptyItem(P_OBJ + "/plate");
}
