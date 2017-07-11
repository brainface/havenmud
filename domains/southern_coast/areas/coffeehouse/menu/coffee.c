#include <lib.h>
#include <meal_types.h>
void NukeMe();
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("coffee");
  SetShort("a cup of coffee");
  SetId( ({ "coffee", "cup" }) );
  SetAdjectives( ({ "cup", "of" }) );
  SetMass(5);
  SetLong("This cup of coffee has been carefully brewed.  The "
          "coffee in it looks very refreshing.  Maybe you should "
          "<drink> it?.");
  SetMealType(MEAL_DRINK|MEAL_CAFFEINE);
  SetStrength(35);
  SetMealMessages(
    "You drink a cup of coffee.",
    "$N drinks a cup of coffee."
    );
}
