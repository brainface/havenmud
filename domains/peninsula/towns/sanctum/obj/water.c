#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("water");
  SetShort("a flask of water");
  SetMass(0);
  SetLong("This is a flask of water.  Perhaps you could <drink> it.");
  SetMealType(MEAL_DRINK);
  SetStrength(50);
  SetMealMessages("You drink your water.","$N drinks some water.");
  SetEmptyName("flask");
  SetEmptyShort("an empty flask");
  SetEmptyLong("This is an empty flask.");
  }
