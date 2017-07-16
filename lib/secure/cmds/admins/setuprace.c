#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

void InputStartingAge(string, string);
void InputStartingTowns(string, string);

mixed cmd(string arg) {
	object who = this_player();
	if (!arg) {
		who->eventPrint("Setup which race?");
		return 1;
		}
	SETUP_D->AddRace(arg);
	who->eventPrint("For race \"" + arg + "\", enter a starting age: ");
	input_to( (: InputStartingAge, arg :) );
	return 1;
}

void InputStartingAge(string race, string sage) {
	int age = to_int(sage);
	if (!sage || sage == "") {
		age = SETUP_D->GetStartingAge(race);
		this_player()->eventPrint("Starting age left at " + age);
	}
	SETUP_D->SetStartingAge(race, age);
	this_player()->eventPrint("For race \"" + race + "\", enter starting towns (comma seperated): ");
	input_to( (: InputStartingTowns, race :) );
}

void InputStartingTowns(string race, string stowns) {
	string *towns = explode(stowns, ",");
	if (!sizeof(towns)) {
		towns = SETUP_D->GetTowns(race);
		this_player()->eventPrint("Starting towns left as " + implode(towns, ", "));
		}
	SETUP_D->SetTowns(race, towns);
	this_player()->eventPrint("Race has been added!");
}

string GetHelp() {
	return "If you need to ask, you shouldn't be messing with this command.";
}

