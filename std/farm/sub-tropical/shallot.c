#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("shallot");
  SetShort("a shallot");
  SetId( ({ "shallot","" }) );
  SetAdjectives( ({"","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(15);
  SetLong("The shallot plant is a large onion with a "
          "sweet taste. It is redish in color and "
          "is the size of a human child head.");
  SetMass(7);
  }
