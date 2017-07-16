#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("navigate");
  SetRules("", "STR");
  SetErrorMessage("Navigate to what town?");
  SetHelp("Syntax:    \"navigate\" \n"
          "           \"navigate <town>\" \n"
	        "By navigating while in a ship with proper equipment, the "
	        "pilot can attempt to determine their location. By default, "
	        "you will attempt to determine your relative distance to "
	        "Haven Town.  However, should you choose you can attempt "
	        "to determine your distance from " + SAILING_D->GetTowns() + "."
          );
}

mixed can_navigate() {
	if (this_player()->GetSleeping()) return "You're in dreamland.";
	if (this_player()->GetParalyzed()) return "You cannot move.";
	if (this_player()->GetStaminaPoints() < 50) return "You're too tired.";
	if (!vehiclep(environment(this_player()))) {
		return "But you are not in a vehicle!";
	}
	return 1;
}

mixed can_navigate_str(string str) {
  if (str == "assassin" && this_player()->GetKeyName() != "malus") {
    return "You don't seem to have an accurate map to Assassin Isle.";
    }
  if (member_array(str, SAILING_D->GetTownArray()) == -1) {
    return "You can't seem to navigate to " + str + ".";
  }
  return can_navigate();
}

mixed do_navigate() {
	if (!this_player()->GetProperty("homedock")) {
	  this_player()->SetPermanentProperty("homedock", "haven");
	  }
	this_player()->AddStaminaPoints(-20);
	send_messages( "attempt", 
	  "$agent_name $agent_verb to determine the ship's location.",
	  this_player(), 0, environment(this_player()) );
	environment(this_player())->eventScan(this_player(), this_player()->GetProperty("homedock"));
	return 1;
}

mixed do_navigate_str(string str) {
  this_player()->SetPermanentProperty("homedock", str);
  return do_navigate();
}
