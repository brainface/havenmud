#include <lib.h>
#include <meal_types.h>
#include "../castle.h"
inherit LIB_MEAL;

int doJump();

static void create() {
  meal::create();
  SetKeyName("lake");
  SetId( ({ "lake" }) );
  SetShort("a pristine lake");
  SetLong("This is a clean, clear lake.  From the surface at any part "
    "of the lake the bottom can be seen.  The water looks pure and clean "
    "enough to drink.  Small reeds grow along the bottom and fish can "
    "be seen darting about their business.  Fenfir trees press in on "
    "all sides of the lake, leaving small shorelines and further "
    "making this an ideal location for idle time.");
  SetPreventGet("You cant get a lake.");
  SetMass(10000);
  SetInvis(1);
  SetEmptyItem(C_OBJ + "lake");
  SetStrength(50);
  SetMealMessages( ({
    "$N drink from a lake.",
    "$N drinks from a lake.",
  }) );
}
