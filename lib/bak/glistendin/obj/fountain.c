#include <lib.h>
#include <meal_types.h>
#include "../glim.h"
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("pool");
  SetShort("a still pool");
  SetMealType(MEAL_DRINK);
  SetLong("Icy, dark water fills the pool in the center of the Great Hall. "
    "Darkness drifts silently only a few feet below the surface, "
    "preventing any precise measurement of the pool's true depth from "
    "being gathered.");
  SetPreventGet("Just how do you plan to do that?");
  SetEmptyItem(G_OBJ + "fountain");
  SetStrength(50);
  SetMealMessages( ({ "$N drink from the pool.", 
                      "$N drinks from the pool.", 
                }) );
 }
