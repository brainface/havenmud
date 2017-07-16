#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("sammich");
  SetId( ({ "sammich"}) );
  SetAdjectives( ({ "white", "bread", "toasted" }) );
  SetShort("a white bread toasted sammich");
  SetMass(5);
  SetLong("This is a delicious looking sammich. There's a layer of blue cheese, "
                "fire roasted spider parts and a lathering of mayonaise on toasted white bread.");
  SetMealType(MEAL_FOOD);
  SetStrength(15);
  SetPortions(8);
  SetMealMessages(
    "The sammich makes an audible crunch as you tear into the spider parts.",
    "$N eats a crunchy sammich of spider parts.");
}
