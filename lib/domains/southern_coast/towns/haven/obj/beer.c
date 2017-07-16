#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("beer");
  SetShort("a jug of beer");
  SetId( ({ "beer", "jug" }) );
  SetAdjectives( ({ "jug", "of" }) );
  SetLong("This is a jug of beer.  Perhaps you could <drink> it.");
  SetMealType(MEAL_DRINK|MEAL_ALCOHOL);
  SetStrength(30);
  SetMealMessages("You drink from a jug of beer.",
                  "$N drinks from a jug of beer.");
  SetEmptyName("jug");
  SetEmptyShort("an empty jug");
  SetEmptyLong("This is a jug.");
  SetPortions(5);
}
