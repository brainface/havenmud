#include <lib.h>
#include <meal_types.h>
#include <domains.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("fountain");
  SetId( ({ "fountain", }) );
  SetAdjectives( ({  }) );
  SetShort("a fountain");
  SetPortions(-1);
  SetLong(
    "A small stone fountain of a simple design. "
    "The red water of the pure and holy blood river flows "
    "into a basin, and then back through a pipe to the river."
  );
  SetStrength(20);
  SetMealType(MEAL_DRINK);
  SetMealMessages( ({
    "You drink from the fountain.",
    "$N drinks from the fountain.",
  }) );
  SetInvis(1);
  SetPreventGet("");
}
