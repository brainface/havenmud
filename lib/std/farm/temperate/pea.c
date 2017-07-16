#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("pea");
  SetShort("a pea pod");
  SetId( ({ "pea","pod" }) );
  SetAdjectives( ({"green","full" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(10);
  SetLong("This is a full green pea pod.");
  SetMass(2);
  }
