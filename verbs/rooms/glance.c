// Amelia
// Give you the status of all livings in the room.

#include <vision.h>
#include <lib.h>
inherit LIB_VERB;

mixed can_glance();
mixed do_glance();

static void create() {
   ::create();
   SetVerb("glance");
   SetRules("");
   SetHelp("Syntax:      \"glance\"   \n"
           "\nProvides information about all visible living "
           "creatures in your room and possible exits.");
   SetErrorMessage("Simply glance?");
}

mixed can_glance() {
    int i;
    switch( i = this_player()->GetEffectiveVision() ) {
       case VISION_BLIND:
           return "You are blind and can see nothing.";
           break;
       case VISION_TOO_DARK:
           return "It is much too dark to see.";
           break;
       case VISION_DARK:
           return "It is too dark to see.";
           break;
       case VISION_TOO_BRIGHT:
           return "It is much too %^YELLOW%^bright%^RESET%^ to see.";
           break;
       case VISION_BRIGHT:
           return "It is too %^YELLOW%^bright%^RESET%^ to see.";
           break;
    }

   if(this_player()->GetSleeping()) { return "But you're sleeping!"; }
   return 1;
}

mixed do_glance() {
   string array resp= ({ });
   object array livs;
   string str;
   string exits, enters;
   float h;
   
   livs = filter(all_inventory(environment(this_player())), (: living :));
   livs -= filter(livs, (: immortalp :) );

   send_messages( ({ "glance" }),"$agent_name $agent_verb around.",this_player(),0,
                    environment(this_player()));
   foreach(object ob in livs) {
     if(ob->GetInvis()) {
        } else {
      str = ob->GetCapName();
      h = percent(ob->GetHealthPoints(), ob->GetMaxHealthPoints());
      if( h < 10.0 ) str += " is mortally wounded.";
      else if( h < 20.0 ) str += " is near death.";
      else if( h < 30.0 ) str += " is severely injured.";
      else if( h < 40.0 ) str += " is badly injured.";
      else if( h < 50.0 ) str += " is hurt.";
      else if( h < 60.0 ) str += " is slightly injured.";
      else if( h < 70.0 ) str += " has some cuts and bruises.";
      else if( h < 80.0 ) str += " is in decent shape.";
      else if( h < 90.0 ) str += " is quite keen.";
      else str += " is in top condition.";
      message("info",str,this_player());
    }
   }
   if (sizeof(environment(this_player())->GetExits()))
     message("info", "You could go " + conjunction(environment(this_player())->GetExits()) + ".", this_player());
   if (sizeof(environment(this_player())->GetEnters()))
     message("info", "You could enter " + conjunction(environment(this_player())->GetEnters()) + ".", this_player());
   return 1;
}
