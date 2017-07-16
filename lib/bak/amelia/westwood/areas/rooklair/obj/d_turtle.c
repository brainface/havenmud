#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("turtle");
  SetId( ({ "turtle","dragon" }) );
  SetAdjectives( ({ "dragon" }) );
  SetShort("a dragon turtle");
  SetLong("A dragon turtle that has a tough looking shell.");
  SetMass(120);
  SetMealType(MEAL_FOOD);
  SetStrength(150);
  SetMealMessages("It taste pretty yummy.", "$N tears into a dragon turtle.");
}
