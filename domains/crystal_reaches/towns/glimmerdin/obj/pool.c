#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("pool");
  SetShort("a pool");
  SetMealType(MEAL_DRINK);
  SetLong(
    "This pool is deep and dark. occasionally within, fish can be "
    "seen swimming and attempting to reach morsels of food."
    );
  SetPreventGet("You attempt to take the pool and only get wet.");
  SetPortions(-1);
  SetStrength(45);
  SetInvis(1);
  SetMealMessages( ({ 
  	 "$N drink from the pool.", 
     "$N drinks from the pool.", 
     }) );
 }
