#include <lib.h>
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("hyperjump");
	SetSynonyms( ({ "warp" }) );
	SetRules("STR");
	SetErrorMessage("Hyperjump <system>\n"
	                "Use this command to hyperjump (or \"warp\") to another system. \n"
	                "Be warned that trying to warp too far can be very, very bad."
	                );
	SetHelp("Syntax:          hyperjump X Y Z  \n"
	        "Enter this command with the amounts of change you are "
	        "ordering along the star charts. Less experienced "
	        "jump pilots should stick with very small jumps, though "
	        "larger jumps are more fuel effecient.");
}

mixed can_hyperjump_str(string x) {
	object who = this_player();
	object ship = environment(this_player());
	if (!vehiclep(ship)) return "Try it in a ship for best results!";
	if (ship->CanHyperjump(who, x) != 1) 
		return ship->CanHyperjump(who, x);
	if (who->GetStaminaPoints() < 50) { return "You are too tired."; }
	return 1;
}

mixed do_hyperjump_str(string x) {
	object who = this_player();
	object ship = environment(who);
	send_messages("order",
	  "$agent_name $agent_verb the ship into hyperspace.",
	  who, 0, ship);
	ship->eventHyperjump(who, x);
	if (who->GetSkillLevel("piloting") <= 45) {
   	who->AddStaminaPoints(-50 + who->GetSkillLevel("piloting"));
   } else who->AddStaminaPoints(-5);
	return 1;
}
