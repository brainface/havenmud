#include <lib.h>
#include <position.h>
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("board");
	SetRules("OBJ");
	SetErrorMessage("Board what ship?");
	SetHelp("Syntax:      board <ship>   \n"
	        "This is the verb which allows you to get onto a ship.\n"
	        "See also: <help ships>");
}

mixed can_board_obj() {
	object who = this_player();
	if (who->GetParalyzed()) return "You are paralyzed and cannot move.";
	if (who->GetSleeping()) return "You cannot sleepwalk.";
	return 1;
}

mixed do_board_obj(object ship) {
	object who = this_player();
	if (who->GetPosition() != POSITION_STANDING) {
	  who->eventForce("stand up");
	}
	if (who->GetPosition() != POSITION_STANDING) {
	  who->eventPrint("You can't seem to stand up and board the ship.");
	  return 1;
	}
	who->eventMoveLiving(ship, "$N boards " + ship->GetName() + ".",
	                           "$N has boarded the ship.");
	return 1;
}
