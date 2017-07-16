#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;
 
static void create() {
   meal::create();
   SetKeyName("beer");
   SetId( ({ "beer","godbeer","godbeer<tm>","mug" }) );
   SetShort("a mug of GodBeer<tm>");
   SetLong("It's beer.  The best imaginable.  What's best is that "
           "it never runs out..");
   SetMass(2);
   SetMealType(MEAL_FOOD);
   SetStrength(1);
   SetMealMessages("A tingly warm feeling spreads throughout your "
                   "body as you drink the mug down.  The mug "
                   "quickly refills itself.",
                   "$N noisily drinks some beer.");
   SetSmell("It smells like alcohol.");
   SetTouch("It's wet and a little fizzy.");
}

void init() {
   ::init();
   add_action("drink", "drink");
}
 
int drink(string args) {
   if(args != "beer") {
        return 0;
   }
   if(!creatorp(this_player())) {
      message("my_action","This is the food for immortals, not for "
              "mere beings like you, that live and die!",this_player());
     return 1;
   }
   message("my_action","A tingly warm feeling spreads throughout your "
                   "body as you drink the mug down.  The mug "
                  "quickly refills itself.",
            this_player());
   message("other_action",this_player()->GetName() + " drinks "
           "a mug of beer.",environment(this_player()),
           this_player());
   return 1;
}

mixed direct_smell_obj() {
   return smell::direct_smell_obj();
}
