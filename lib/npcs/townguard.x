#include <lib.h>
#include <daemons.h>
inherit LIB_NPC;
int GuardTown(object who);

static void create() {
  ::create();
  SetEncounter( (: GuardTown :) );
}

/* The only difference between LIB_TOWNGUARD and LIB_NPC 
 * is that LIB_TOWNGUARD automagically jumps in to help
 * citizens that are being attacked.
 */

object *CheckFriends() {
	object *tmp = ({ });
	if (!GetTown() || GetTown() == "Wilderness") {
	  debug("Bad Town in a TownGuard.  Which idiot coded this file: ");
	}
  tmp = all_inventory(environment());
  tmp = filter(tmp, (: $1->GetTown() == GetTown() :) );
	return tmp;
}

int GuardTown(object who) {
	int x = who->GetReputation(GetTown());
	if (x < -500) {
		eventForce("yell Leave this town, " + who->GetCapName() + "!");
		eventForce("attack " + who->GetKeyName());
		return 1;
	}
	if (x < -250) {
		eventForce("speak I'd leave this place if I were you, " + who->GetCapName() + ".");
		eventForce("emote glares harshly at " + who->GetCapName() + ".");
		return 0;
	}
	if (x < 0) {
		eventForce("speak Be on your best behaviour, " + who->GetCapName() + ".");
		return 0;
	}
	if (x > 500) {
		eventForce("wave " + who->GetKeyName());
		eventForce("speak Nice to see " + GetTown() + " has friends like you, " + who->GetCapName() + ".");
		return 0;
	}
	if (x > 250) {
		eventForce("wave " + who->GetKeyName() );
		return 0;
	}
	return 0;
}