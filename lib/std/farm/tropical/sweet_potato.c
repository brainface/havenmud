#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("sweat potato");
  SetShort("a sweet potato");
  SetId( ({ "potato","sweet potato" }) );
  SetAdjectives( ({"sweet","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(30);
  SetLong("This is a large potato that is orange "
          "on the inside and has a much sweeter "
          "taste than it's duller cousin.");
  SetMass(10);
  }
