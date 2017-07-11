#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("salad");
  SetId( ({ "salad", "greens" }) );
  SetAdjectives( ({ "large", "leafy"}) );
  SetShort("a large leafy salad");
  SetMass(10);
  SetLong("This is a large leafy salad with red beans and sliced grapes. "
          "Drizzled on the salad is a grape vingear and oil dressing." );
  SetMealType(MEAL_FOOD);
  SetPortions(2);
  SetStrength(50);
  SetMealMessages("You eat some of the large salad. The grapes makes the salad taste sweet.",
                  "$N eats some of the large salad.");
}

