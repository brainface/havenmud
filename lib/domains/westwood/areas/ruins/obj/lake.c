#include <lib.h>
#include <meal_types.h>
#include "../castle.h"
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("lake");
  SetShort("a shimmering lake");
  SetMealType(MEAL_DRINK);
  SetLong("This stunning lake is so perfect it looks like it "
          "is almost magical in nature. The surface of the "
          "lake shimmers off natural light with grace. It is "
          "a small lake considering the amount of water entering "
          "it from the waterfall. A border of sand lines the lake "
          "shore.");
  SetPreventGet("It slips through your hands. The body of "
                "water wins this round.");
  SetPortions(-1);
  SetStrength(25);
  SetInvis(1);
  SetMealMessages( ({ 
   "$N drink from the shimmering lake.", 
   "$N drinks from the shimmering lake.", 
  }) );
}