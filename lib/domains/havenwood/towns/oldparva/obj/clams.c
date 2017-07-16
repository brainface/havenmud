#include <lib.h>
#include <meal_types.h>
#include "parva.h"
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("clams");
   SetShort("a plate of steamed clams");
   SetId( ({ "plate","clams","clam" }) );
   SetAdjectives( ({ "plate of","steamed" }) );
   SetLong("The clams are mostly still in there shells; a few "
           "shell-less clams and clam-less shells lie around "
           "the plate of nearly 30 steamed clams.  Garlic "
           "and butter and some other seasonings have been "
           "put on the clams.");
   SetMass(35);
   SetStrength(30);
   SetMealType(MEAL_FOOD);
   SetMealMessages("$N eat a plate of steamed clams.",
                   "$N eats a plate of steamed clams.");
   SetEmptyItem(P_OBJ + "/plate");
}
