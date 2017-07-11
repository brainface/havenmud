#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("garlic");
  SetShort("a garlic");
  SetId( ({ "garlic","" }) );
  SetAdjectives( ({"","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(25);
  SetLong("This is a garlic plant.");
  SetMass(12);
  }
