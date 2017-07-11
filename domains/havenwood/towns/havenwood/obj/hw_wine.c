#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("wine");
  SetShort("a cup of wine");
  SetLong("This is a cup of sweet wine made from the grapes in Havenwood. "
          "Perhaps you could <drink> it.");
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetStrength(35);
  SetMass(10);
  SetMealMessages("You drink a cup of wine.","$N drinks a cup of wine.");
  SetEmptyName("cup");
  SetEmptyShort("an empty cup");
  SetEmptyLong("This is a wooden cup.");
 }
