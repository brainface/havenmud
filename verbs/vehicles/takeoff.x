/*  Take Off! */
#include <lib.h>
#include <daemons.h>
#define SPACE "/domains/realspace/virtual/space/"
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("takeoff");
	SetRules("");
	SetErrorMessage("Takeoff?");
	SetHelp("Syntax:       takeoff   \n"
	        "Use this syntax to launch a shuttle into orbit from the surface.");
}

mixed can_takeoff() {
	object who = this_player();
	object ship = environment(who);
	object where;
	string world, tmp;
	
	if (!vehiclep(ship)) return "Try doing that from a ship.";
	where = environment(ship);
	if (sscanf(base_name(where), "/worlds/%s/%s", world, tmp) != 2) 
	  return "Sensors cannot determine your current location.";
	if (where->GetClimate() == "indoors" || where->GetClimate() == "underground") 
	  return "You must be on the surface for that.";
	if (!(PLANETS_D->GetPlanetLocation(world)))
	  return "You have no clear path to the stars.";
	return ship->CanTakeoff(who);
}

mixed do_takeoff() {
	object who = this_player();
	object ship = environment(who);
	object where;
	string world, tmp;
	int success = who->eventCheckSkill("piloting", 5, 0, 0);
	where = environment(ship);
	if (sscanf(base_name(where), "/worlds/%s/%s", world, tmp) != 2) 
	  return "Sensors cannot determine your current location.";
	tmp = PLANETS_D->GetPlanetLocation(world);
	ship->AddCrystals(-5);
	if (success <= 0) {
		who->eventPrint("You fail to launch the ship into orbit.");
		return 1;
	}
	send_messages("order", 
	  "$agent_name $agent_verb the ship to take off.",
	  who, 0, environment(who) );
	ship->eventMoveLiving(SPACE + tmp, 
	         "$N takes off into orbit.", "$N enters orbit from " + world + ".");
	return 1;
}
