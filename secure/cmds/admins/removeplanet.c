#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
	string planet, where;
	object who = this_player();
	int x, y, z;
	
	if (!args) {
	  who->eventPrint("removeplanet \"LOCATION\" + <STD_PLANETS> \"filename\"");
	  return 1;
	}
	if (sscanf(args, "%s %s", where, planet) != 2) {
		who->eventPrint("You need to specify WHERE and WHAT FILE");
		return 1;
	}
	who->eventPrint("Where: " + where + " PlanetFile " + planet);
	PLANETS_D->RemovePlanet(where, planet);
	sscanf(where, "%d,%d,%d", x, y, z);
	if (member_array(STD_PLANETS + planet, PLANETS_D->CheckPlanets(x, y, z)) == -1) {
		who->eventPrint("Planet successfully removed.");
		return 1;
	}
	who->eventPrint("Failed to remove planet.");
	return 1;
}
