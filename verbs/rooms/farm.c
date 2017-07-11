#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("farm");
	SetRules("with OBJ");
	SetErrorMessage("Farm with what?");
	SetHelp("Syntax:   farm with OBJ  \n\n"
	        "Allows you to farm with an object.  This object must be "
	        "a farming item.");
}
	
mixed can_farm_with_obj() {
	object who = this_player();
	object where = environment(who);
	if (who->GetParalyzed()) {
		return "You can do nothing at all.";
	}
	if (who->GetSleeping()) {
		return "You are asleep!";
	}
	if (where->GetTown() != "Wilderness" || where->GetProperty("no farming")
	    || where->GetClimate() == "indoors") {
		return "You cannot farm here.";
	}
	
	return 1;
}

mixed do_farm_with_obj() {
	FARM_D->AddFarmer(this_player());
	send_messages("start", "$agent_name $agent_verb farming.", 
	              this_player(), 0, environment(this_player()) );
	return 1;
}
