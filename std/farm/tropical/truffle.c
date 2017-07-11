#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("truffle");
  SetShort("a small truffle");
  SetId( ({ "truffle","small truffle" }) );
  SetAdjectives( ({"small","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(15);
  SetLong("This is a small fungus used as food. They "
          "are black and grow a few inches under the "
          "ground.");
  SetMass(5);
  }
