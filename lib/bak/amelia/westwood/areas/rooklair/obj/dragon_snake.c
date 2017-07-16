#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("snake");
  SetId( ({ "snake","dragon" }) );
  SetAdjectives( ({ "dragon" }) );
  SetShort("a dragon snake");
  SetLong("A dragon snake thats looks kinda disgusting.");
  SetMass(100);
  SetMealType(MEAL_FOOD);
  SetStrength(125);
  SetMealMessages("It taste like chicken!", "$N eats a dragon snake.");
}
