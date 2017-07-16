/*    /verbs/items/eat.c
 *    from the Dead Soulsr2 Object Library
 *    created by Descartes of Borg 951113
 *    Version: @(#) eat.c 1.3@(#)
 *    Last modified: 96/11/03
 */

#pragma save_binary

#include <lib.h>
#include <rounds.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("smoke");
    SetErrorMessage("Smoke what?");
    SetRules("OBJ");
    SetHelp("Syntax: <smoke THING>\n\n"
	    "Allows you to smoke something.\n"
	    "See also: bait, cast, drink, fish, eat");
}


void eventSmoke(object who, object what) {
    if( !what ) {
	return;
    }
    return (mixed)what->eventSmoke(who);
}

mixed can_smoke_obj() { 
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
   if( this_player()->GetParalyzed() ) {
	   return "You cannot do anything.";
   }
   return 1;
}

mixed do_smoke_obj(object ob) {
  if( this_player()->GetInCombat() ) {
	  this_player()->SetAttack(0, (: eventSmoke, this_player(), ob :), ROUND_OTHER);
     } else {
	    eventSmoke(this_player(), ob);
    }
    return 1;
}
