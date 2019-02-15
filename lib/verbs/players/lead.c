/*  Allows players to possibly help a target follow.
 *  created by Rush@Dead Souls
 */

#pragma save_binary

#include <lib.h>
#include "include/lead.h"

inherit LIB_VERB;

static void create() {
  verb::create();
  SetVerb("lead");
  SetRules("LIV");
  SetErrorMessage("Who would you like to lead?");
  SetHelp("Syntax: lead LIVING\n"    
    "\n"
    "Allows one to assist a living being who is "
    "attempting to follow.\n"
    "\n"
    "See also: evade, follow, tracking, stealth\n");
}

mixed can_lead_liv() {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
   return 1;
}

mixed do_lead_liv(object ob) {
  if(ob->GetHitcher()) {
    this_player()->eventPrint(ob->GetName() + " looks a little tied up at the moment. (help drive)");
    return 1;
  }
  if(!ob->IsFollowing(this_player())) {
    this_player()->eventPrint(ob->GetName() + " is not following you.");
    return 1;
  }
  if( this_player()->SetAllowed(ob, 1) ) {
    ob->eventPrint((string)this_player()->GetName() + " is now leading you.");
    this_player()->eventPrint("You are now leading " + ob->GetName() + ".");
  }
  else this_player()->eventPrint("You are not empowered to lead " + ob->GetName() + ".");
  return 1;
}


