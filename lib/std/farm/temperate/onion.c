#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("onion");
  SetShort("a large onion");
  SetId( ({ "onion","" }) );
  SetAdjectives( ({"large","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(40);
  SetLong("This is a rather large onion.");
  SetMass(15);
  }
