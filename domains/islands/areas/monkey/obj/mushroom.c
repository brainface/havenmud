// Aerelus

#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
 
static void create() {
   meal::create();
   SetKeyName("curious mushroom");
   SetId( ({ "mushroom", "shroom" }) );
   SetAdjectives( ({ "red","curious" }) );
   SetShort("a curious mushroom");
   SetLong("This small, red mushroom is covered with white speckles. "
           "There is a thin layer of transparent slime on the top. The "
           "stalk is very thick, and appears to have been nibbled by a small "
           "animal or insect.");   
   SetMass(1);
   SetMealType(MEAL_POISON|MEAL_FOOD|MEAL_ALCOHOL);
   SetStrength(50);
   SetMealMessages("You feel ill, yet content, as the curious mushroom "
                     "takes effect.",                      
                   "$N looks content after eating a curious mushroom.");   
}