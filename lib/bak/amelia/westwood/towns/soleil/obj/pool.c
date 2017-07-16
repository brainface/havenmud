// Amelia@Haven

#include <lib.h>
inherit LIB_MEAL;
#include <meal_types.h>
#include "../soleil.h"
 
static void create() {
   meal::create();
   SetInvis(1);
   SetKeyName("clear pool");
   SetId( ({ "clear pool","pool" }) );
   SetAdjectives( ({ "clear","deep","clean" }) );
   SetShort("a clear pool");
   SetMealType(MEAL_DRINK);
   SetLong("This pool is deep, clear, and clean.");
   SetPreventGet("You cannot take a pool of water!");
   SetEmptyItem(S_OBJ + "pool");
   SetStrength(15);
   SetMealMessages( ({ "You drink from the pool of water.",
                   "$N drinks from the pool of water." }) );
}
