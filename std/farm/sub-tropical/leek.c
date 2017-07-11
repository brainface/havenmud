#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("leek");
  SetShort("a leek");
  SetId( ({ "leek","" }) );
  SetAdjectives( ({"onion like","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(25);
  SetLong("This is an onion like plant with a long stem. "
          "It has a thick leathery skin with small red "
          "spots.");
  SetMass(12);
  }
