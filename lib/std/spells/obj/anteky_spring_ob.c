#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("spring");
  SetShort("a spring spewing from between two rocks");
  SetId( ({ "spring","rocks"}) );
  SetAdjectives( ({ "spewing","from","between","two","rocks","spring" }) );
  SetLong("It looks as if the ground has recently burst upward here, "
    "allowing this spring to bubble to the surface. The water looks "
    "clear and free of contamination."
  );
  SetSmell("The spring smells of minerals.");
  SetMealType(MEAL_DRINK);
  SetPortions(1);
  SetStrength(40);
  SetPreventGet("You can't carry a spring!");
  SetMealMessages( ({
    "You drink deeply from a spring.  The water is very refreshing.",
    "$N drinks deeply from a spring."
  }) );
}

