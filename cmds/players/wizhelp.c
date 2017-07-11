/*
 * Wizhelp cmd
 * Prints a message to Imm+ saying a player needs help
 * 
 * Written by Zaxan@Haven
 */

#include <lib.h>

inherit LIB_DAEMON;

int cmd(string str) {
    object *imms = filter(users(), (: immortalp($1) && !$1->GetBlocked("all") :) );

    if(creatorp(this_player()))
    {
	this_player()->eventPrint("If you need help from an Immortal, get it yourself!");
	return 1;
    }
    
    message("broadcast", "%^YELLOW%^BOLD%^[wizhelp]%^RESET%^ "+
	    capitalize(this_player()->GetKeyName()) + " requests assistance from "
	    "an Immortal.", imms);
    this_player()->eventPrint("Your request for assistance from an Immortal has been sent.\n"
	                      "If an Immortal is available, you will be contacted shortly.");
    unguarded( (: log_file, "reports/wizhelp", capitalize(this_player()->GetKeyName()) + " requested "
		  "assistance from " + file_name(environment(this_player())) + " at " + ctime(time()) + ".\n" :));
    return 1;
}

string GetHelp() {
    return ("Syntax: <wizhelp>\n\n"
            "Sends a request to all Immortals (excluding Angels) asking for help. If\n"
	    "one is available when you send the request, you will be contacted via a\n"
	    "tell which you can then reply to.\n\nAbusing this command is not recommended.");
}
