#include <lib.h>
#include <meal_types.h>
void NukeMe();
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("dwarven cream");
  SetShort("a warm mug of dwarven cream");
  SetId( ({ "cream", "mug" }) );
  SetAdjectives( ({ "warm", "mug", "of", "dwarven" }) );
  SetMass(5);
  SetLong(
    "Brewed from a secret recipe from Glimmerdin, this beverage "
    "has something for everyone.  A thirst quencher, a hint of "
    "caffeine for a pick me up, and a hint of alcohol to start "
    "your morning off right."
    );
  SetMealType(MEAL_DRINK|MEAL_CAFFEINE|MEAL_ALCOHOL);
  SetStrength(50);
  SetMealMessages(
    "You down a warm mug of dwarven cream.",
    "$N downs a warm mug of dwarven cream."
    );
}
