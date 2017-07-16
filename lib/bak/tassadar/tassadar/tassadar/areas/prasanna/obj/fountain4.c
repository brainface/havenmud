#include <lib.h> 
#include <meal_types.h>
#include "prasanna.h"

inherit LIB_MEAL;

static void create() {
        meal::create();
        SetKeyName("fountain");
  SetPortions(-1);
        SetShort("a fountain of a turtle");
        SetId("fountain","turtle");
        SetMealType (MEAL_DRINK);        
        SetLong("This fountain is carved from a rose-gray granite. Sunlight "
                "refracts in subtle waves from the turtle's rough-chiseled "
                "shell, shines along its carefully smoothed stone head and "
                "beak. That beak is stretched wide and gaping in what can "
                "only be described as a grin, from which must have issued "
                "the heated water for this bath..");
        SetPreventGet("The fountain is far too heavy to move."); 
        SetEmptyItem(PR_OBJ "/fountain4");
        SetStrength(0);
        SetMealMessages("The fountain is empty.","$N tries to drink from an empty fountain.");
}

