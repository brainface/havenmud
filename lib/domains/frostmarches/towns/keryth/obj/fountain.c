#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("fountain");
  SetShort("a fountain");
  SetMealType(MEAL_DRINK);
  SetLong("This is the local fountain.  The citizens of Keryth come here "
         "often to drink from it, as it is a nice place to relax and talk "
         "about life.");
  SetPreventGet("You cannot take the fountain.");
  SetPortions(-1);
  SetStrength(18);
  SetMealMessages( ({
    "$N drink from a fountain.", 
    "$N drinks from a fountain."
  }) );
}
