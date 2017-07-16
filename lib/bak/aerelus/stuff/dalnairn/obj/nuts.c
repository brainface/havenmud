// Dalnairn
// Aerelus

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("nuts");
  SetId( ({ "nuts", "handful"}) );  
  SetShort("a handful of nuts");  
  SetLong(
  "These nuts have been sprinkled with some mixed spices and been slightly "
  "roasted. They look delicious."
  );
  SetAdjectives( ({ "handful", "of" }) );
  
  SetMass(1);
  SetMealType(MEAL_FOOD);
  SetStrength(5);
  SetPortions(1);
  SetMealMessages(
    "You eat the handful of nuts. They taste wonderful, but aren't very "
    "filling.",
    "$N eats a handful of nuts.");
}
