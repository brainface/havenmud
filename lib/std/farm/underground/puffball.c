#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("puffball mushroom");
  SetShort("a puffball mushroom");
  SetId( ({ "puffball", "mushroom" }) );
  SetAdjectives( ({"large","white" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(50);
  SetLong("This is a large white puffball mushroom "
          "that grows in dark moist places. The ball "
          "is slightly fuzzy and smooth to the touch.");
  SetMass(5);
  }
