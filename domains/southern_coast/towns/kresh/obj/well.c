#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetPortions(-1);
  SetShort("a deep well");
  SetKeyName("well");
  SetId( ({ "well" }) );
  SetAdjectives( ({ "deep" }) );
  SetPreventGet("");
  SetLong(
    "This well is the main reason that the horde has chosen this area as "
    "a semi permanent base camp. The well is deep and cool and refreshing."
    );
  SetStrength(20);
  SetMealType(MEAL_DRINK);
  SetMealMessages( ({
    "You drink deeply from the well.",
    "$N drinks deeply from the well.",
  }) );
}
