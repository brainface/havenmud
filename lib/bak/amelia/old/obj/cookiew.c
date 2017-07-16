#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;
 
static void create() {
   meal::create();
   smell::create();
   touch::create();
   SetKeyName("cookie");
   SetId( ({ "wedding cookie","cookie" }) );
   SetAdjectives( ({ "wedding" }) );
   SetShort("a large wedding cookie");
   SetLong("Pretty multi-colored sugar sprinkles cover the pale sugar "
           "cookie, as well as small silver balls arranged in the "
           "shape of two people holding hands.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("You munch away at the delicous cookie.",
                   "$N munches happily at a delicous cookie.");
   SetSmell("Warm buttery smells come from the cookie.");
   SetTouch("The cookie is warm and soft, with your fingers leaving "
            "tiny imprints in the surface.  As you lift your hands "
            "away, you notice that some of the sprinkles have "
            "stuck to your hand.");
}

void init() {
   ::init();
   add_action("eat","eat");
}

int eat(string args) {
   if(args != "cookie") {
      return 0;
   }
   if(!creatorp(this_player())) {
      message("my_action","This is the food for immortals, not for "
              "mere beings like you, that live and die!",this_player());
     return 1;
   }
   message("my_action","You munch away at the delicous cookie.",
            this_player());
   message("other_action",this_player()->GetName() + " munches happily "
           "at a delicous wedding cookie.",environment(this_player()),
           this_player());
   return 1;
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}