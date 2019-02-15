/*    /verbs/vehicles/unhitch.c
 * unhitch a thing from whatever it's hitched to
 */

#include <lib.h>
// #include <position.h>
// #include <rounds.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("unhitch");
    SetRules("OBJ");
    SetErrorMessage("Unhitch what?");
    SetHelp(
      "Syntax: <unhitch [horse]\n"
      "                <unhitch [wagon]\n"
      "\n"
      "Allows you to unhitch a horse from a wagon or vis versa.\n"
      "You need not specify what you're unhitching it from.\n"
      "See also: mount, hitch, drive, board, hijack.\n"
    );
}

mixed can_unhitch_obj() {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    if( this_player()->GetParalyzed() ) {
        return "You cannot do anything!";
    }
    return 1;
}

// for now, just unhitch everything.
mixed do_unhitch_obj(object carthorse) {
  // will not handle errors at all.

  // handle ownership of whatever we're targeting. (If the horse and cart 
  // somehow get different owners, note that this check might work targetting 
  // one but not the other.
  if (carthorse->GetOwner() != this_player()->GetKeyName() && carthorse->GetDriver() != this_player()->GetKeyName()) {
  	this_player()->eventPrint("You do not own " + carthorse->GetShort() + " and are not registered as its driver.");
  	return 0;
  }
  carthorse->GetHitcher()->eventReleaseHitch(0);
  return carthorse->eventReleaseHitch(this_player());
}

