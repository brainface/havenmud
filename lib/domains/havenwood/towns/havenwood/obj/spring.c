
#include <lib.h>
#include <meal_types.h>
#include "../wood.h"
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("spring");
  SetShort("a small spring");
  SetMealType(MEAL_DRINK);
  SetLong("A small spring gurgles here, bubbling up a bit of clear water into a "
    "pool before burrowing back underground. It looks safe to drink.\n"
    );
  SetPreventGet("You'd need a shovel and a few hundred years to move that.");
  SetPortions(-1);
  SetStrength(45);
  SetMealMessages( ({
        "$N drink from a spring.",
    "$N drinks from a spring.",
    }) );
 }

