#include <lib.h>
inherit LIB_ITEM;
 
int check_get();

static void create() {
   item::create();
   SetKeyName("balishae's bottle");
   SetId( ({ "balishae's bottle","bottle" }) );
   SetAdjectives( ({ "balishae's" }) );
   SetShort("Balishae's bottle");
   SetLong("This plain bottle has the name Balishae written on "
           "the underside.  It is filled with a lot of rick, hearty "
           "milk.");
   SetMass(10);
   SetValue(5000);
   SetPreventGet( (: check_get :) );
}
 
int check_get() {
   if(this_player()->GetKeyName()!="balishae" || "amelia" ) {
            return 0;
   }
   else return 1;
}

void init() {
   ::init();
   add_action("drink","drink");
}

int drink(string args) {
   if(args != "milk") {
      return 0;
   }
   else {
      message("my_action","You drink some deliciously rich milk from "
                          "your bottle.",this_player());
      message("other_action",this_player()->GetKeyName() + " drinks some "
         "of a silky smooth white substance from Balishae's bottle.",
         environment(this_player()),this_player());
      return 1;
   }
   return 0;
}
