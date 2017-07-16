/* Minor Failure.  Causes fainting. */
#include <position.h>
#include <lib.h>
inherit LIB_FAILURE;


int eventFail(object who, object spell) {
	
	send_messages( ({ "collapse", "faint" }),
	  "$agent_name $agent_verb to the ground and $agent_verb.",
	  who, 0, environment(who) );
	who->SetPosition(POSITION_LYING);
	who->SetSleeping(random(3) + 1);
}
