#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;
 
static void create() {
   meal::create();
   SetKeyName("chocolate chip cookie");
   SetId( ({ "cookie" }) );
   SetAdjectives( ({ "huge","chocolate chip" }) );
   SetShort("a huge chocolate chip cookie");
   SetLong("Chips cover every square centimeter of this delectable "
           "chocolate chip cookie.  It seems to beg one to take "
           "a bite.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("You munch away at the delicous cookie.",
                   "$N munches happily at a delicous chocolate chip "
                   "cookie.");
   SetSmell("Fresh, warm cookie scents fill the air.");
   SetTouch("The cookie is warm and soft, but crisp around the edges.  "
            "Some chocolate from the chips gets on your hand.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
