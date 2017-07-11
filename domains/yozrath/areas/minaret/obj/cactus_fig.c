#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("fig");
  SetId( ({ "fig" }) );
  SetAdjectives( ({ "cactus" }) );
  SetShort("a cactus fig");
  SetMass(5);
  SetLong(
    "This pear shaped fruit is plump and orange.  "
    "The skin is thin and smooth giving the fruit a glossy "
    "appearance."
  );
  SetMealType(MEAL_FOOD);
  SetStrength(30);
  SetPortions(3);
  SetMealMessages(
    "You take a bite from a cactus fig.",
    "$N takes a bite from a cactus fig.");
}
