// Amelia@Haven

#include <lib.h>
#include <meal_types.h>
 
inherit LIB_MEAL;
 
static void create() {
   meal::create();
   SetDestroyOnSell(1);
   SetKeyName("fish");
   SetId( ({ "fish" }) );
   SetAdjectives( ({ "cave" }) );
   SetShort("a cave fish");
   SetLong("This blind, yet edible, cave fish, appears to be "
           "rather bland and tasteless, but wet and slimy.");
   SetMass(10);
   SetMealType(MEAL_FOOD);
   SetStrength(30);
   SetMealMessages("It slides down funny.", "$N eats a cave fish.");
}
