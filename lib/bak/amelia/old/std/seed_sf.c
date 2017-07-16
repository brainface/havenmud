#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("sunflower seed");
   SetShort("a sunflower seed");
   SetId( ({ "seed" }) );
   SetAdjectives( ({ "sunflower","sun","flower","black" }) );
   SetLong("The black seed idly waits to be cracked and eaten.");
   SetMass(1);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("The seed chews up with a nutty flavor, but the "
                   "shell has to be spit out; it fades into "
                   "the ground.","$N eats a sunflower seed and spits "
                   "out the shell.");
}
