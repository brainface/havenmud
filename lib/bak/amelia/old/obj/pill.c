#include <lib.h>
inherit LIB_ITEM;
 
int CheckPerson();
 
static void create() {
   item::create();
   SetKeyName("pill");
   SetShort("a birth control pill");
   SetId( ({ "pill" }) );
   SetAdjectives( ({ "birth","control" }) );
   SetLong("The pill is small and white and looks like any other pill, "
           "but luckily the words 'birth control' are written on it, so "
           "one can tell what kind of pill it is.  Another lucky thing "
           "for people like Syra is that it's a GodPill<tm>, a product "
           "of GodFood<tm>.  Therefore, it will never actually go away, "
           "no matter how many times you <swallow> it.  Syra will need "
           "that, considering that she is married to Duuktsaryth, who "
           "feels it necessary to have sex multiple times a day with "
           "someone he's merely dating (let alone people he's actually "
           "married too!).");
   SetPreventGet( (: CheckPerson :) );
}
 
void init() {
   ::init();
   add_action("swallow","swallow");
}
 
int swallow(string arg) {
   if(arg != "pill") return 0;
   if(this_player()->GetGender() != "female") {
      message("system","Birth control pills don't work on guys.  DUH.",
              this_player());
   }
   if(this_player()->GetCapName() == "Syra") {
      send_messages( ({ "swallow" }),"$agent_name $agent_verb "
                        "a birth control pill dry.",this_player(),0,
                        environment(this_player()));
      message("system","Woo!  Good thing you swallowed that Syra.  "
              "You're too young for babies.",this_player());
      return 1;
   }
   message("system","Don't you see the little 'For Syra Only' tab on "
           "the pill?  You'll poison yourself.  Sheeesh!",this_player());
   return 1;
}
 
int CheckPerson() {
   if(this_player()->GetCapName() != "Syra") return 0;
   else return 1;
}
