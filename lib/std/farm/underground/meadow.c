#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("mushroom");
  SetShort("a meadow mushroom");
  SetId( ({ "meadow","mushroom" }) );
  SetAdjectives( ({"white","" }) );
  SetMealType(MEAL_FOOD);
  SetSmell( ([ "default" : "This mushroom has "
                 "a very sweet odor."]) );
  SetStrength(5);
  SetLong("This is a small white mushroom with small "
          "dimples that are pinkish in color. It is a "
          "stalk mushroom with a soft puffy head.");
  SetMass(1);
  }
