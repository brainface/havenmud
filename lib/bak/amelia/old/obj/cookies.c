#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;
 
static void create() {
   meal::create();
   SetKeyName("cookie");
   SetId( ({ "sugar cookie","cookie" }) );
   SetAdjectives( ({ "sugar" }) );
   SetShort("a sizable sugar cookie");
   SetLong("Pretty green sugar-sprinkles cover the Christmas-tree "
           "shaped sugar cookie.  A red hot sits on it's tippity-top,"
           " playing the Christmas star, and silver balls are "
           "pressed into the cookie at various spots along it.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("You munch away at the delicous cookie.",
                   "$N munches happily at a delicous sugar cookie.");
   SetSmell("Warm buttery smells come from the cookie.");
   SetTouch("The cookie is warm and soft, with your fingers leaving "
            "tiny imprints in the surface.  As you lift your hands "
            "away, you notice that some of the green sprinkles have "
            "stuck to your hand.");
}
 
void init() {
   ::init();
   add_action("eat", "eat");
}
 
int eat(string args) {
   if(args != "cookie") {
      write("You can't eat that.");
      return 1;
   }
   message("my_action","You munch away at the delicious cookie.",
            this_player());
   message("other_action",this_player()->GetName() + " munches happily "
           "at a delicious sugar cookie.",environment(this_player()),
           this_player());
   eventDestruct();
   return 1;
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
