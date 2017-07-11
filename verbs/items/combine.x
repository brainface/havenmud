#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("combine");
	SetRules("OBJ with OBJ");
	SetErrorMessage("Combine what with what?");
	SetHelp("Syntax:            combine OBJ with OBJ\n\n"
	        "Using this syntax, people can try to mix 2 things to make "
	        "something else.");
}

mixed can_combine_obj_with_obj() {
	object who = this_player();
	if (who->GetSleeping()) {
		send_messages("mutter",
		  "$agent_name $agent_verb in $agent_possessive sleep.",
		  who, 0, environment(who));
		return "You are asleep!";
	}
	if (who->GetParalyzed()) { return "You cannot move!"; }	
	return 1;	      
}

mixed do_combine_obj_with_obj(object first, object second) {
	string fname, sname;
	
	fname = first->GetKeyName();
	sname = second->GetKeyName();
	
	if (!(ALCHEMY_D->CanCombine(first, second, this_player()))) {
		send_messages("fail", 
		  "$agent_name $agent_verb to combine " +
		     first->GetShort() + " and " + second->GetShort() + ".",
		  this_player(), 0, environment(this_player()) );
	  return 1;
	}
	ALCHEMY_D->eventCombine(first, second, this_player());
	return 1;
}
