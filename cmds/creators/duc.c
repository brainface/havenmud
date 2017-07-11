#include <lib.h>
inherit LIB_DAEMON;

int cmd(string args) {
  string filename;
  string error;
  object what;
  object who = this_player();
  
  what = present(args, environment(who));
  if (!what) what = present(args, who);
  if (!what) {
    who->eventPrint("duc what?");
    return 1;
    }
  filename = base_name(what);
  filename->eventDestruct();
  error = catch(call_other(filename, "????"));
  if (error) {
    who->eventPrint("DUC ABORTED!!!");
    who->eventPrint("Error: " + error);
    return 1;
    }
  what->eventDestruct();
  what = new(filename);
  what->eventMove(environment(who));
  send_messages("reload", "$agent_name $agent_verb $target_name.", 
    who, what, environment(who) );
  return 1;
  }
  
string GetHelp(string blah) {
    return "Syntax: <duc [object]> \n\n"
	     "This updates a file, then dests and reloads an object in your"
	     "environment. Superior to DUC 1.0 because it does not dest the"
	     "object if the file fails to update. See \"help format\" for "
           "information about how to specify objects.";
}
	        
    
    
  