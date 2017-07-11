#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;
 
static void create() {
   meal::create();
   SetKeyName("ginger cookie");
   SetId( ({ "cookie" }) );
   SetAdjectives( ({ "huge","ginger","tasty" }) );
   SetShort("a huge tasty ginger cookie");
   SetLong("One can hardly resist the urge to eat this "
           "scrumptious looking ginger cookie.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("You munch away at the delicous cookie.",
                   "$N munches happily at a delicous ginger cookie.");
   SetSmell("Fresh, warm cookie scents fill the air.");
   SetTouch("The cookie is warm and soft, but crisp around the edges.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
