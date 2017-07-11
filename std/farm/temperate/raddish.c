#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("radish");
  SetShort("a radish");
  SetId( ({ "radish","" }) );
  SetAdjectives( ({"red","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(40);
  SetLong("This is a deep red radish.");
  SetMass(10);
  }
