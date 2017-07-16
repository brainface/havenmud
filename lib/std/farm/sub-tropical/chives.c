#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("chive");
  SetShort("a bunch of chives");
  SetId( ({ "chive","chives" }) );
  SetAdjectives( ({"bunch","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(5);
  SetLong("These are green leafed chives grouped in "
          "a small bunch of stalks.");
  SetMass(1);
  }
