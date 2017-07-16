#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;
 
static void create() {
   meal::create();
   touch::create();
   SetKeyName("cookie");
   SetId( ({ "cookie" }) );
   SetAdjectives( ({ "sugar","sizable" }) );
   SetShort("a sizable sugar cookie");
   SetLong("Pretty green sugar-sprinkles cover the star "
           "shaped sugar cookie.  A red hot sits in the exact center "
           "of the cookie, and at the end of each of the five legs, "
           "a small silver ball is pressed in.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("You munch away at the delicous cookie.",
                   "$N munches happily at a delicous sugar cookie.");
   SetSmell("Warm buttery smells come from the cookie.");
   SetTouch("The cookie is warm and soft, with your fingers leaving "
            "tiny imprints in the surface.  As you lift your hands "
            "away, you notice that some of the green sprinkles have "
            "stuck to your hand, but they quickly fall off.");
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
