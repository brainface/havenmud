#include <lib.h>
#include "../shrine.h"
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("fountain");
  SetPreventGet("The fountain is much too large to move.");
  SetMealType(MEAL_DRINK);
  SetMealMessages("You drink from the ornate fountain.",
                  "$N drinks from the fountain.");
  SetStrength(80);
  SetId( ({ "fountain" }) );
  SetShort("a small ornate fountain");
  SetAdjectives( ({ "small", "ornate" }) );
  SetPortions(-1);
  SetLong("Small yet beautiful, this fountain shows"
          " no sign of age. The bowl has been carved"
          " from a white marble and shaped into an"
          " open lotus flower. The water within looks"
          " clear and refreshing.");
}

