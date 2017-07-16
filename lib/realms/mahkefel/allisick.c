#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("noodles");
  SetId( ({ "noodles","chicken","vodka","bowl" }) );
  SetAdjectives( ({ "chicken","and","noodles","of" }) );
  SetShort("a bowl of chicken and noodles (and overpoured vodka)");
  SetMass(20);
  SetLong("Not really just like grandma used to make when you were sick. Your eyes water "
    "due to the savory smell and also seriously that is some vodka oh god "
    "it's burning your eyes.");
  SetMealType(MEAL_FOOD|MEAL_ALCOHOL);
  SetPortions(4);
  SetStrength(100);
  SetMealMessages(
    "You feel so better about everything. Also you want to sing.",
    "$N slurps up some delicious soup.");
}

