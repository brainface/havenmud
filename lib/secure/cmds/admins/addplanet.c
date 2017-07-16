#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
	string planet, where, name;
	object who = this_player();
	int x, y, z;
	
	if (!args) {
	  who->eventPrint("addplanet \"LOCATION\" + <STD_PLANETS> \"filename\" + name");
	  return 1;
	}
	if (sscanf(args, "%s %s %s", where, planet, name) != 3) {
		who->eventPrint("You need to specify WHERE and WHAT FILE with WHAT NAME");
		return 1;
	}
	who->eventPrint("Where: " + where + " PlanetFile " + planet + " Name:" + name);
	PLANETS_D->AddPlanet(where, planet, name);
	sscanf(where, "%d,%d,%d", x, y, z);
	if (member_array(STD_PLANETS + planet, PLANETS_D->CheckPlanets(x, y, z)) != -1) {
		who->eventPrint("Planet successfully added.");
		return 1;
	}
	who->eventPrint("Failed to add planet.");
	return 1;
}
