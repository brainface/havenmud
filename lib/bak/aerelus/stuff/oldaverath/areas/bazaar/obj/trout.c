#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("trout");
  SetId( ({"trout"}) );
  SetAdjectives( ({"trout","speckled"}) );
  SetShort("a speckled trout");
  SetLong("A long filled out, gray speckled trout.");
  SetMass(150);
  SetMealType(MEAL_FOOD);
  SetStrength(30);
  SetMealMessages("You eat a speckled trout.", 
                  "$N gulps down a speckled trout.");
  }
