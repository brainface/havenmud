#include <lib.h> 
#include <meal_types.h>
#include "prasanna.h"

inherit LIB_MEAL;

static void create() {
        meal::create();
        SetKeyName("fountain");
  SetPortions(-1);
        SetShort("a fountain of a seahorse");
        SetId("fountain","seahorse");
        SetMealType (MEAL_DRINK);        
        SetLong("Seahorse -- This fountain is carved from a rose-gray "
                "granite. It is a sublime and alien marvel, with eyes "
                "faceted like precious stones, and a body with scales "
                "chased in patterns that create ripples of alternating "
                "light in shadow. It balances neatly on its tail, fins "
                "fully extended, snout arched over the bath to provide "
                "water that no longer exists.");
        SetPreventGet("The fountain is far too heavy to move."); 
        SetEmptyItem(PR_OBJ "/fountain3");
        SetStrength(0);
        SetMealMessages("The fountain is empty.","$N tries to drink from an empty fountain.");
}

