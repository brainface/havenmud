#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("beer");
  SetShort("a mug of beer");
  SetLong("This is a mug of beer.  Perhaps you could <drink> it.");
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetStrength(40);
  SetMass(15);
  SetMealMessages("You drink a mug of beer.","$N drinks a mug of beer.");
  SetEmptyName("mug");
  SetEmptyShort("an empty mug");
  SetEmptyLong("This is a mug.");
 }
