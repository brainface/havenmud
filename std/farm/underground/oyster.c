#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("mushroom");
  SetShort("an oyster mushroom");
  SetId( ({ "oyster","mushroom" }) );
  SetAdjectives( ({"brown","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(5);
  SetLong("This is a small brown mushroom with small "
          "black pimples. It is a mossy mushroom "
          "with a low stalk and a flat head.");
  SetMass(1);
  }
