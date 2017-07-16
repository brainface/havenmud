#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("carrot");
  SetShort("a carrot");
  SetId( ({ "carrot" }) );
  SetAdjectives( ({"long","orange" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(20);
  SetLong("It is a long orange carrot.");
  SetMass(5);
  }
