#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
   meal::create();
   SetShort("a channel");
   SetInvis(2);
  SetLong("This small channel runs from the bottom of "
        "the sculpture to the wall and continues outside "
        "of the observatory.  It is "
        "made from some form of resin.");
  SetMealType(MEAL_DRINK);
  SetPortions(-1);
  SetStrength(45);
  SetMealMessages( ({
    "$N drink from the channel",
    "$N drinks from the channel",
    }) );
   SetId( ({"channel"}) );
   SetKeyName("channel");
  SetAdjectives( ({ "small" }) );
   SetMaterials( ({"natural"}) );
  SetPreventGet("You can't pick up the channel!");
}
