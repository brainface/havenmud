#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("shark");
  SetId( ({"shark"}) );
  SetAdjectives( ({"shark","small","blue"}) );
  SetShort("a small blue shark");
  SetLong("A well built small blue shark.");
  SetMass(150);
  SetMealType(MEAL_FOOD);
  SetStrength(150);
  SetMealMessages("You eat a blue shark.", 
                  "$N swallows a blue shark.");
  }
