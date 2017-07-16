#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("tainted spring");
  SetShort("a shallow tainted spring");
  SetId( ({ "spring", "water", }) );
  SetAdjectives( ({ "shallow", "tainted" }) );
  SetLong("This spring bubbles up merrily from the ground.  The water seems to "
          "dissapate shortly after splashing back upon itself, leaving no "
          "watery mess.");
  SetSmell("The spring has a faintly alcoholic smell.");
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetPortions(1);
  SetStrength(40);
  SetPreventGet("You can't carry a spring!");
  SetMealMessages( ({
    "You sip from a spring.  It has a faintly alcoholic taint.",
    "$N sips from a cool, refreshing spring."
  }) );
}

 