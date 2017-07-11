/* A fountain */
#include <lib.h>
#include "../tairi.h"
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("fountain");
  SetPreventGet("The fountain is much too large to move.");
  SetMealType(MEAL_DRINK);
  SetMealMessages("You drink from the flowing fountain.",
                  "$N slurps noisily from the fountain.");
  SetStrength(80);
  SetId( ({ "fountain" }) );
  SetShort("a large bubbling fountain");
  SetAdjectives( ({ "large", "bubbling" }) );
  SetPortions(-1);
  SetLong("This large fountain throws water high into the air. "
          "Its base is formed in the shape of a flower bloom, with "
          "the open end spitting the water into the sky. The clear "
          "water looks cool and refreshing, obviously a source of "
          "noisy joy when citizens choose to drink from it.");
}
