#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;
 
static void create() {
   meal::create();
   SetKeyName("cookie");
   SetId( ({ "chocolate chip cookie","cookie" }) );
   SetAdjectives( ({ "chocolate","chip","chocolate chip" }) );
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

/*
void init() {
   ::init();
   add_action("eat", "eat");
}
 
int eat(string args) {
   if(args != "cookie") {
      write("You can't eat that.");
      return 1;
   }
   if(!creatorp(this_player())) {
      message("my_action","This is the food for immortals, not for "
              "mere beings like you, that live and die!",this_player());
     return 1;
   }
   message("my_action","You munch away at the delicous cookie.",
            this_player());
   message("other_action",this_player()->GetName() + " munches happily "
           "at a delicous chocolate chip cookie.",environment(this_player()),
           this_player());
   eventDestruct();
   return 1;
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
*/
