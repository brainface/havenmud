/*    /secure/cmds/player/bug.c
 *    from the Dead Soulsr1 Object Library
 *    the command interface to the NM IV bug tracking system
 *    created by Descartes of Borg 950925
 */

#include <lib.h>
#include <daemons.h>
#include <message_class.h>

inherit LIB_DAEMON;

static void EndReport(string type, string data, string file);

static void create() {
    daemon::create();
    SetNoClean(1);
}

mixed cmd(string str) {
  string env;
  if (vehiclep(environment(this_player()))) {
    env = file_name(environment(this_player())) + " @ " + file_name(environment(environment(this_player())));
  } else {
    env = file_name(environment(this_player()));
  }
  env = short_file(env);
  EndReport(0, env, 0);
  return 1;
}

static void EndReport(string type, string data, string file) {
    string tmp;
    int x;

    if( !type ) {
	message("system", "Choose a bug type from among the following:\n",
		this_player());
	message("system", "\tidea (some nifty idea to add to the game)",
		this_player());
  message("system", "\tquest idea (some nifty QUEST idea to add to the game)",
		this_player());
	message("system", "\ttypo (misspelling, lexigraphical weirdness)",
		this_player());
	message("system", "\tunexplained behaviour (something "
		"contrary to how you would expect it)", this_player());
	message("system", "\truntime (one of those nasty error messages)\n",
		this_player());
	message("system", "\tother\n", this_player());
	message("prompt", "Enter type: ", this_player());
	input_to( (: EndReport :), data, 0);
	return;
    }
    if( !file ) {
	file = DIR_TMP "/" + (string)this_player()->GetKeyName();
	rm(file);
	message("system", "Enter in a description of the bug.  When done, "
		"enter a period on a line by itself.", this_player());
	this_player()->eventEdit(file, (: EndReport, type, data, file :));
	return;
    }
    if( !(tmp = read_file(file))) {
	message("system", "Bug report aborted.", this_player());
	rm(file);
	return;
    }
    if( file_size(file) < 1) {
	message("system", "Bug report aborted.", this_player());
	rm(file);
	return;
    }

    rm(file);
    if( type == "runtime" ) {
	mapping last_error;

	if( last_error = (mapping)this_player()->GetLastError() )
	  data += "\n" + (string)master()->standard_trace(last_error) + "\n";
    }
    if( !(x = (int)BUGS_D->eventReport((string)this_player()->GetCapName() ,
				   type, tmp, data)) ) {
	message("system", "Bug report failed.", this_player());
	return;
    }

    message("system", "Bug reported, thank you!  Your tracking id is " + x + ".", this_player());
 //   message("system", "Have you considered taking the Angel Test?", this_player());
    if (!creatorp(this_player()))
    {
	CHAT_D->eventSendChannel("Bug Report", "error", 
	  capitalize(this_player()->GetKeyName()) + " has reported bug ID " + x + ". (" + type + ")");
    }
}

string GetHelp(string str) {
    string tmp;

    tmp = "Syntax: <bug>\n";
    tmp += "\n";
    tmp += "The command interface to the Dead Souls Bug Tracking System.  "
      "You can simply type \"bug\" and be prompted for further options, "
      "or, if you understand the system, pass command line arguments "
      "to the bug command to make things go faster.  This system allows "
      "players to report bugs or ideas.";
    return tmp;
}
    
