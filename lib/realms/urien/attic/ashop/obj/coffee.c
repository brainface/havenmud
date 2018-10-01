#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("coffee");
  SetShort("a cup of coffee");
  SetId( ({ "coffee", "cup" }) );
  SetAdjectives( ({ "cup", "of" }) );
  SetMass(5);
  SetLong("This coffee is black with no creme or "
          "any special ingredients. It smells old and slightly "
          "burned from cooking too long. The coffee sits "
          "in a plain white cup which could be disposed of "
          "quickly after drinking from it.");
  SetMealType(MEAL_DRINK|MEAL_CAFFEINE);
  SetStrength(40);
  SetMealMessages(
    "You drink a cup of coffee. You immediately feel results.",
    "$N drinks a cup of coffee."
    );
}

