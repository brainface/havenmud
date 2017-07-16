#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
 
static void create() {
   meal::create();
   SetKeyName("bottle");
   SetId( ({ "bottle of milk","milk","bottle" }) );
   SetAdjectives( ({ "none" }) );
   SetShort("a bottle of milk");
   SetLong("This bottle is full of delicously warm milk.");
   SetMass(10);
   SetMealType(MEAL_DRINK);
   SetStrength(1);
   SetMealMessages("You drink some milk.",
                   "$N drinks some milk.");
}
 
void init() {
   ::init();
   add_action("drink", "drink");
}
 
int drink(string args) {
   if(args != "milk") {
      write("You can't drink that.");
      return 1;
   }
   message("my_action","You drink some rich milk.",
            this_player());
   message("other_action",this_player()->GetName() + "drinks some "
           "milk.",environment(this_player()),
           this_player());
   return 1;
}
