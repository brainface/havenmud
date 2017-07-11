#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
   meal::create();
   SetShort("a small waterfall");
   SetLong(
  "Water flows out of the opening from the water channel "
  "above, landing in a collection pool which starts the lower "
    "channel's path."
   );
  SetMealType(MEAL_DRINK);
  SetPortions(-1);
  SetStrength(45);
  SetMealMessages( ({
    "$N drink from a waterfall",
    "$N drinks from a waterfall",
    }) );
   SetId( ({"waterfall", "opening"}) );
   SetAdjectives( ({ "small" }) );
   SetKeyName("waterfall");
  SetPreventGet("The water splashes off your hands as you play with it.");
}
