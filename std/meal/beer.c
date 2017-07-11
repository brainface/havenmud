#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("beer");
  SetShort("a mug of beer");
  SetLong(
     "This tall, frothing mug holds within it the much desired alcoholic "
     "beverage widely known as beer. It fizziles with a slight bubbling effect "
     "as the dark amber liquid begs to be drank. "
  );
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetStrength(30);
  SetMealMessages(
     "The smooth taste is very refreshing as you drink a mug of beer.",
     "$N drinks a mug of beer."
  );
  SetEmptyName("mug");
  SetEmptyShort("an empty mug");
  SetEmptyLong(
     "This tall, hollow mug once contained within it a liquid of some sort. "
     "Traces of a dark amber substance still line the bottom inside this mug. "
  );
 }
