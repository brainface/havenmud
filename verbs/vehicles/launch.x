/*  LAUNCH!  */
#include <lib.h>
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("launch");
	SetRules("STR on STR");
	SetErrorMessage("Launch attack on what ship?");
  SetHelp("Syntax:    launch attack on <SHIP>  \n"
          "Use this command to attack an enemy ship.\n"
          "See also: help ships");
}

mixed can_launch_str_on_str(string wep, string str) {
	object ship = environment(this_player());
	object who = this_player();
	object target;
	if (!vehiclep(ship)) {
		return "But you are not in a vehicle!";
	}
	target = present(str, environment(ship));
	if (who->GetSleeping()) return "You are asleep!";
	if (who->GetParalyzed()) return "You cannot move!";
	if (who->GetStaminaPoints() < 50) return "You are too tired.";
	if (str == "ship") return "You must be more specific.";
	return ship->CanLaunchWeapons(who, target, wep); 
}

mixed do_launch_str_on_str(string wep, string str) {
	object who = this_player();
	object ship = environment(who);
	object target = present(str, environment(ship));
	int cost;
	if (!target) {
		who->eventPrint("Your target is no longer present.");
		return 1;
		}
	switch(who->GetSkillLevel("sailing")) {
	  case 0..20:
	    cost = 50;
	    break;
	  case 21..40:
	    cost = 40;
	    break;
	  case 41..80:
	    cost = 30;
	    break;
	  case 81..160:
	    cost = 20;
	    break;
	  case 161..999:
	    cost = 10;
	    break;
	  case 1000..10000:
	    cost = 1;
	    break;
	  default:
	    cost = 50;
	    break;
	  }	
	send_messages("launch",
	  "$agent_name $agent_verb an attack against $target_name!",
	  who, target,  ship );
	message("system", capitalize(ship->GetShort()) + " launches an attack on " + target->GetShort() + "!",
	  environment(ship), ({ ship, target }) );
	who->AddStaminaPoints(-cost);
	ship->eventLaunchWeapons(who, target, wep);
	return 1;
}
