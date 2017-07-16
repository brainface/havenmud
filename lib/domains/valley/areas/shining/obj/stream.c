#include <lib.h>
#include <meal_types.h>
#include "../sf.h"
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("stream");
  SetShort("a stream");
  SetMealType(MEAL_DRINK);
  SetLong("The stream here is extremely clean and clear. It's blue in "
          "color with soft green tinge through it. The bottom of the "
          "stream is not visible from here. There appears to be no way "
          "to enter.");
  SetPreventGet("Its a stream, you cannot take it.");
  SetPortions(-1);
  SetStrength(45);
  SetInvis(2);
  SetMealMessages( ({ 
    "$N drink from a stream.", 
    "$N drinks from a stream.", 
    }) );
}

