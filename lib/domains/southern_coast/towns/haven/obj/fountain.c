#include <lib.h>
#include <meal_types.h>
#include "../haven.h"
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("fountain");
  SetShort("a fountain");
  SetMealType(MEAL_DRINK);
  SetLong("This is the local fountain.  The citizens of Haven Town. \n"
          "come here often to drink from it, as it is a nice place \n"
          "to relax and talk about life.");
  SetPreventGet("You cannot take the fountain.");
  SetPortions(-1);
  SetStrength(45);
  SetMealMessages( ({ 
  	"$N drink from a fountain.", 
    "$N drinks from a fountain.", 
    }) );
 }
