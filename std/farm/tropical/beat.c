#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("beet");
  SetShort("a large beet");
  SetId( ({ "beet","" }) );
  SetAdjectives( ({"large","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(30);
  SetLong("This is a large beet.");
  SetMass(15);
  }
