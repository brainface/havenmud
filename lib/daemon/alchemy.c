#include <lib.h>
#include <save.h>
inherit LIB_DAEMON;

private mapping CanCombines;
void LoadStuff();
void SaveStuff();
int CanCombine(object first, object second, object who);
int eventCombineItems(object first, object second, object who);


static void create() {
	::create();
	CanCombines = ([]);
	LoadStuff();
}

void LoadStuff() {
	unguarded( (: restore_object, SAVE_ALCHEMY :) );
	SaveStuff();
}

void SaveStuff() {
	unguarded( (: save_object, SAVE_ALCHEMY :) );
}

int AddCombine(string first, string second, string targetfile) {
	if (!CanCombines[first]) CanCombines[first] = ([]);
	if (!CanCombines[second]) CanCombines[second] = ([]);
	CanCombines[first] += ([ second : targetfile ]);
	CanCombines[second] += ([ first : targetfile ]);
	SaveStuff();
	return CanCombines[first][second] == targetfile;
}

int RemoveCombine(string first, string second) {
	map_delete(CanCombines[first], second);
	map_delete(CanCombines[second], first);
	SaveStuff();
	return 1;
}


string GetCombine(string first, string second) {
	return CanCombines[first][second];
}

int eventCombine(object first, object second, object who) {
	object combine = new(CanCombines[first->GetKeyName()][second->GetKeyName()]);

/* Insert various skill checks here. */	

	send_messages(({ "combine", "form" }),
	  "$agent_name $agent_verb " + first->GetShort() + " and " + second->GetShort() +
	  " and $agent_verb $target_name!", who, combine, environment(who));
	first->eventDestruct();
	second->eventDestruct();
	combine->eventMove(who);
	return 1;
}

int CanCombine(object first, object second, object who) {
	string fname, sname;
	
	fname = first->GetKeyName();
	sname = second->GetKeyName();
	
	/* Insert more checks here. */
	
	if (!mapp(CanCombines[fname])) {
		who->eventPrint("!CanCombines[first]");
		return 0;
		}
	if (!CanCombines[fname][sname]) {
		who->eventPrint("!CanCombines[1st][2nd]");
		return 0;
		}
	return 1;
}

	