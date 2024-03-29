/*    /verbs/players/request.c
 *    from the Dead Souls V Object Library
 *    created by Descartes of Borg 951219
 */

#include <lib.h>
#include <conditions.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("request");
    SetRules("STR from LIV");
    SetErrorMessage("Request what from whom?");
    SetHelp("Syntax: <request SOMETHING from LIVING>\n\n"
	    "This allows you to ask livings things for particular things.  "
	    "For example, in Newbieland, you might 'request clothes from "
	    "man'.  This command behaves identically to 'ask LIVING for "
	    "SOMETHING'.\n\n"
	    "See also: ask");
}

mixed can_request_str_from_liv() {
  if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
  }
  if( this_player()->GetParalyzed() ) {
	  return "You cannot do anything.";
  }
  if (this_player()->GetConditionFlag(CONDITION_PREVENT_TALK)) {
    return "You can't seem to speak.";    
  }
	return 1;

}

mixed do_request_str_from_liv(string str, object who) {
    this_player()->eventPrint("You request " + str + " from " +
			      (string)who->GetName() + ".");
    environment(this_player())->eventPrint((string)this_player()->GetName() +
					   " requests " + str + " from " +
					   (string)who->GetName() + ".",
					   ({ who, this_player() }));
    if( !((int)who->eventRequest(this_player(),
				 remove_article(lower_case(str)))) )
      who->eventPrint((string)this_player()->GetName() + " requests " +
		      str + " from you.");
    return 1;
}
