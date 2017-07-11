#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
   meal::create();
   SetShort("a channel");
   SetInvis(2);
  SetLong("This small channel was engineered along side the path "
        "for water to flow down from the top of the minaret.  It is "
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
