#include <lib.h>
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("wake");
	SetRules("LIV");
	SetErrorMessage("Wake whom?");
        SetHelp(
            "Syntax: <wake [living]>\n\n"
            "This command is used to wake a non-magically sleeping person. \n\n"
            "See also: sleep"
         );
}

mixed can_wake_liv() {
	object who = this_player();
	if (who->GetSleeping()) {
		return "You can't wake someone while you're sleeping!";
	}
	if (who->GetParalyzed()) {
		return "You are unable to move.";
	}
	return 1;
}

int do_wake_liv(object sleepy) {
	object who = this_player();
	
	send_messages( "wake",
	  "$agent_name $agent_verb $target_name up.", 
	  who, sleepy, environment(who) );
	sleepy->SetSleeping(0);
  return 1;
}
