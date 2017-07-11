//coded by Syra 8/97
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("rabbit meat");
  SetId(({"rabbit meat","meat","chuck","piece","section","rabbit"}));
  SetAdjectives(({"rabbit","fresh","grisley"}));
  SetShort("a fresh chunk of rabbit meat");
  SetLong("A fresh section of rabbit.");
  SetMass(2);
  SetMealType(MEAL_FOOD);
  SetStrength(7);
  SetMealMessages("You eat a piece of rabbit meat.", 
                  "$N winces as " + nominative(environment(this_object()))
                  + " eats a grisley piece of rabbit meat.");
}


/* Approved by Amelia on Sun Sep 14 20:58:28 1997. */
