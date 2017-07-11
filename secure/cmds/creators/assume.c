//
// The 'assume' command
// Takes control of an NPC.
// Original author unknown
// Re-organized and modified by Zaxan@Haven
//

#include <lib.h>
#include <objects.h>
#include <daemons.h>

inherit LIB_HELP;

private string *channels = ({ });

static void create() {
   help::create();
   SetHelp("Syntax: <assume NPC> \n\n"
           "Allows you to take control of an NPC.  Use 'restore' "
           "to gain back control of your own body.");
}

mixed cmd(string args) {
   object who = this_player();
   object target;
   object assumed = new(OBJ_ASSUME);

   if(angelp(who)) {
      return "Are you trying to make an 'ass' out of 'u' and 'me'?";
   }
   if (!args) return "Assume whom?";
   target = find_living(args);
   if(!target && noncreatorp(find_object(args))) {
      target = find_object(args);
   }
   if(!target) {
      return "No such target.";
   }
   if(userp(target) || target->GetProperty("assuming")) {
      return "Someone is already controlling that person.";
   }
   if(immortalp(target)) return "You cannot assume control of an immortal.";
   target->SetProperty("assumed", who);
   who->SetProperty("assuming", target);
   CHAT_D->eventSendChannel("Assume Report", "reports",
           capitalize(this_player()->GetKeyName()) + " has assumed "+
           target->GetShort()+" ("+file_name(target)+").");
   channels = who->GetChannels();
   assumed->eventMove(target);
   assumed->SetInvis(1);
   target->AddChannel(channels);
   if(!archp(this_player())) {
      unguarded( (: log_file, "assumes", 
                    capitalize(who->GetKeyName())+
                    " assumed "+target->GetKeyName()+ 
                    " ("+base_name(target)+") "+ctime(time())+"\n" :));
   }
   exec(target, who);
   target->eventPrint("%^YELLOW%^BOLD%^Use \"restore\" to regain your "
                      "body.%^RESET%^");
   target->SetRPC(1);
   target->eventDescribeEnvironment();
   return 1;
}
