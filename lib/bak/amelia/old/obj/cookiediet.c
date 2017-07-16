#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;
 
static void create() {
   meal::create();
   smell::create();
   SetKeyName("cookie");
   SetId( ({ "diet cookie","cookie" }) );
   SetAdjectives( ({ "diet" }) );
   SetShort("a tiny diet cookie");
   SetLong("This cookie is an ugly brown-green color.  It's supposed "
           "to taste good, it even has the companies motto, 'eat us!  "
           "We're healthy and we taste good!', written on it in "
           "microscopic letters.  Bland brown frosting with lumps "
           "of who-knows-what in it makes a ring around the edge of the "
           "cookie.");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(100);
   SetMealMessages("You twist your face itto a gross look, "
                      "feeling like you're about to vomit.",
                   "$N looks sick after eating a diet cookie.");
   SetSmell("The cookie smells like musty books that have lived "
            "in a damp corner of a basement for far too long.");
   SetTouch("The cookie is rock solid, it's amazing they aren't "
            "used for building houses instead of bricks.  Small "
            "bumps can be felt where the company motto has been "
            "molded into the cookie.  A little frosting sticks to "
            "your finger, and pondering the taste, you lick it "
            "off--and are immediately sick to your stomach.");
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
   if(!creatorp(this_player())) {
      message("my_action","This is the food for immortals, not for "
              "mere beings like you, that live and die!",this_player());
     return 1;
   }
   message("my_action","You twist your face into a gross look, "
           "feeling like you're about to vomit.",this_player());
   message("other_action",this_player()->GetName() + " looks sick "
           "after eating a diet cookie.",environment(this_player()),
            this_player());
   eventDestruct();
   return 1;
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}