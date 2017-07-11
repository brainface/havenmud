/*  Portia  10-14-98
    A well for both levels of the town.
*/

#include <lib.h>
#include "../../mal.h"
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("well");
  SetShort("a well");
  SetMealType(MEAL_DRINK);
  SetLong("This well seems to be a gathering spot for the citizens "
     "of Malveillant. It also seems to be the only source of water, and "
    "a centerpiece for the town.");
  SetPreventGet("You can't take the well.");
  SetPortions(-1);
  SetStrength(100);
  SetMealMessages( ({ "$N drink from a well.",
                 "$N drinks from a well.",
        }) );
  }


/* Approved by Duuktsaryth on Mon Nov 16 23:27:15 1998. */
