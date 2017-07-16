#include <lib.h>
#include <meal_types.h> 
#include "prasanna.h"

inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("fountain");
   SetShort("a fountain");
   SetMealType(MEAL_DRINK);
   SetLong("This is the central fountain of Prasanna. The fountain is "
           "somewhat of a miracle of engineering, combining elements of "
           "both fire, water, and beauty.");
   SetPreventGet("You cannot take the fountain.");
   SetEmptyItem( PR_OBJ + "/mainfountain");
   SetStrength(45);
   SetMealMessages( ({ "$N drink from a fountain.", 
                       "$N drinks from a fountain.", 
                  }) );
}

