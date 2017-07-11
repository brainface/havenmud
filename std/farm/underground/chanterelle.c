#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  ::create();
  SetKeyName("chanterelle");
  SetShort("a chanterelle");
  SetId( ({ "chanterelle" }) );
  SetAdjectives( ({"nut","" }) );
  SetMealType(MEAL_FOOD);
  SetStrength(5);
  SetLong("This is a large nut flavored mushroom "
          "resembling an acorn for the head and "
          "having a low thick stem. It is hard to "
          "distinguish the head from the stem.");
  SetMass(1);
  }
