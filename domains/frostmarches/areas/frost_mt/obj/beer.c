#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("beer");
  SetShort("a mug of beer");
  SetLong("This mug of beer looks very delicious as it foams out and "
	  "over the top.");
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetStrength(18);
  SetMealMessages("You drink a mug of beer.","$N drinks a mug of beer.");
  SetEmptyName("mug");
  SetEmptyShort("an empty mug");
  SetEmptyLong("This empty mug has the slight scent of alcohol.");
 }
