#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("mine");
	SetRules("with OBJ");
	SetErrorMessage("Mine with what?");
	SetHelp("Syntax:   mine with OBJ  \n\n"
	        "Allows you to mine with an object.  This object must be "
	        "a mining item.");
}
	
mixed can_mine_with_obj() {
	object who = this_player();
	object where = environment(who);
	if (who->GetParalyzed()) {
		return "You can do nothing at all.";
	}
	if (who->GetSleeping()) {
		return "You are asleep!";
	}
  if (where->GetProperty("no mining")) {
		return "You cannot mine here.";
	}
	if (where->GetClimate() != "underground") {
	  return "You must be underground to mine!";
	  }	
	return 1;
}

mixed do_mine_with_obj() {
	MINE_D->AddMiner(this_player());
	send_messages("start", "$agent_name $agent_verb mining.", 
	              this_player(), 0, environment(this_player()) );
	return 1;
}
