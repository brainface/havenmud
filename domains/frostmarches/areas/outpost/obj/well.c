#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("well");
  SetShort("a well");
  SetMealType(MEAL_DRINK);
  SetLong(
    "This well is deep and dark. The water within the well is fresh and cold."
    );
  SetPreventGet("You attempt to take the well but almost fall in.");
  SetPortions(-1);
  SetStrength(30);
  SetInvis(1);
  SetMealMessages( ({ 
    "$N drink cold, fresh water from the well.", 
    "$N drinks from the well.", 
    }) );
 } 