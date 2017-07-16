#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
   meal::create();
   SetKeyName("grain");
   SetShort("a grain pile");
   SetId( ({ "grain pile","pile","grain" }) );
   SetLong("These little specks of grain could be good enough to eat, " 
           "but just barely.");
   SetMass(1);
   SetMealType(MEAL_FOOD);
   SetStrength(5);
   SetMealMessages("The grain is hard to chew up and get down.",
                   "$N eats a pile of grain.");
}