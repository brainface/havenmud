#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("scallion");
  SetShort("a scallion");
  SetId( ({ "scallion","" }) );
  SetAdjectives( ({"small","onion like" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(10);
  SetLong("This is a small, onion like, plant. "
          "It is white with dark green leaves.");
  SetMass(2);
  }
