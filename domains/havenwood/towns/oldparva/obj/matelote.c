#include <lib.h>
#include <meal_types.h>
#include "parva.h"
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("matelote");
   SetShort("a plate of matelote");
   SetId( ({ "plate","matelote" }) );
   SetAdjectives( ({ "plate of" }) );
   SetLong("The matelote dish is a stew of some chopped up "
           "seafood in a red wine sauce.  The seafood looks "
           "like various fish and eel.");
   SetMass(25);
   SetStrength(35);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N eat a plate of matelote.",
                   "$N eats a plate of matelote.");
   SetEmptyItem(P_OBJ + "/plate");
}
