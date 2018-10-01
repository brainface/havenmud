#include <lib.h> 
#include <meal_types.h>
#include "prasanna.h"

inherit LIB_MEAL;

static void create() {

  meal::create();
  SetKeyName("fountain");
  SetShort("a fountain of a merman");
  SetId("merman","fountain");
  SetMealType (MEAL_DRINK);        
  SetPortions(-1);
  SetLong("This fountain is carved from a rose-gray granite. The "
          "merman's smoothly polished upper torso gleams with clearly "
          "delineated muscles, muscles that bulge with the apparent "
          "effort entailed in blowing a conch-shell horn. The water "
          "seems to have come from within the shell.");
  SetPreventGet("The fountain is far too heavy to move."); 
  SetEmptyItem(PR_OBJ "/fountain1");
  SetStrength(0);
  SetMealMessages(
    "The fountain is empty.",
    "$N tries to drink from an empty fountain.");
  }
