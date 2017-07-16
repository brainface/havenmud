#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("latte");
  SetShort("a cup of latte");
  SetId( ({ "cup", "latte" }) );
  SetAdjectives( ({ "cup", "of" }) );
  SetMass(5);
  SetLong(
    "This cup of latte looks smooth and refreshing, "
    "with just a hint of pick-me-up."
    );
  SetMealType(MEAL_DRINK|MEAL_CAFFEINE);
  SetStrength(20);
  SetMealMessages("You drink a latte.","$N drinks a latte.");
  }
