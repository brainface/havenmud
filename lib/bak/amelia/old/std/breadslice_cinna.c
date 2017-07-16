// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("cinnamon bread");
   SetShort("a slice of cinnamon bread");
   SetId( ({ "slice","bread" }) );
   SetAdjectives( ({ "cinnamon","slice of","golden","brown" }) );
   SetLong("The crust of the cinnamon bread is golden brown, and the "
           "insides look fully cooked, with a touch of butter on it, "
           "melted into the bread.");
   SetMass(5);
   SetMealType(MEAL_FOOD);
   SetStrength(4);
   SetMealMessages("The bread tastes rich and good.",
                   "$N eats a slice of cinnamon bread.");
}
