#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("water");
  SetShort("a cup of water");
  SetMass(5);
  SetLong("This is a rather plain looking cup of water. The cup itself is"
          " rather mundane but the water looks great.");
  SetMealType(MEAL_DRINK);
  SetStrength(50);
  SetMealMessages("You drink the water.","$N drinks the water.");
  SetEmptyName("cup");
  SetEmptyShort("an empty cup");
  SetEmptyLong("This is an empty cup.");
  }
