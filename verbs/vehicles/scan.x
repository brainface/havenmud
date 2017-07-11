#include <lib.h>
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("scan");
	SetRules("", "STR");
	SetHelp("Syntax:    \"scan\", \"scan <THING>\" \n"
	        "By scanning while in a ship with proper equipment, the "
	        "pilot can attempt to determine their location in space, "
	        "and scan for any ships in the local area.");
}

mixed can_scan() {
	if (!vehiclep(environment(this_player()))) {
		return "But you are not in a vehicle!";
	}
	return 1;
}

mixed can_scan_str(string str) {
	if (str != "planets" && str != "ships") {
		return "You must either <scan planets> or <scan ships>";
	}
	return can_scan();
}

mixed do_scan() {
	environment(this_player())->eventScan(this_player());
	return 1;
}

mixed do_scan_str(string what) {
	environment(this_player())->eventScan(this_player(), what);
	return 1;
}
