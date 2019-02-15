/*    /verbs/players/sit.c
 *    from the Dead Souls V Object Library
 *    created by Descartes of Borg 960711
 *    Version: @(#) sit.c 1.7@(#)
 *    Last Modified: 96/12/21
 */

#include <lib.h>
#include <position.h>
#include <rounds.h>
#include <conditions.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("sit");
    SetRules("", "down", "down in OBJ", "down on OBJ", 
             "in OBJ", "on OBJ", "up");
    SetErrorMessage("Sit up or down?");
    SetHelp(
      "Syntax: <sit down>\n"
      "                <sit down in [object]>\n"
      "                <sit up>\n\n"
      "Allows you to sit down on the ground or a chair-like object. "
      "It can be really exciting and causes an increase in your rate "
      "of regenerating hp, mp and sp.\n\n"
      "See also: lie, sleep, stand"
    );
}

mixed can_sit_down() {
   if(this_player()->GetSleeping()) {
     return "You cannot do that while sleeping!";
   }
   if( this_player()->GetParalyzed() ) {
     return "You cannot do anything!";
   }
   if( this_player()->GetPosition() != POSITION_STANDING ) {
     return "Did you mean to sit up?";
   }
   if (this_player()->GetConditionFlag(CONDITION_PREVENT_POSITION)) {
     return "Your knees refuse to bend!";
   }
   return 1;
}

mixed can_sit_word_obj() {
	if (this_player()->GetHitcher()) {
	  return "That's going to be really awkward while hitched to something.";	
	}
	if (this_player()->GetRider()) {
	  return "You better not sit on that while something's riding you, you crazy horse-like thing you.";
	}
  return can_sit_down();
}

mixed can_sit_down_word_obj() {
  if (this_player()->GetHitcher()) {
    return "That's going to be really awkward while hitched to something.";	
  }
  if (this_player()->GetRider()) {
    return "You better not sit on that while something's riding you, you crazy horse-like thing you.";
  }
  return can_sit_down();
}

mixed can_sit_up() {
   if(this_player()->GetSleeping()) {
     return "You cannot do that while sleeping!";
   }
   if( this_player()->GetParalyzed() ) {
     return "You cannot do anything!";
   }
   if( this_player()->GetPosition() != POSITION_LYING ) {
     return "Do you mean to sit down?";
   }
   if (this_player()->GetConditionFlag(CONDITION_PREVENT_POSITION)) {
     return "Your knees refuse to straighten!";
   }
   return 1;
}

mixed do_sit_down() {
    return this_player()->eventSit();
}

mixed do_sit_up() {
    return this_player()->eventSit();
}


mixed do_sit_word_obj(string word, object target) {
  if(target->GetChair() ) {
    this_player()->eventPrint("You can't sit on " +target->GetShort()+ " while it's sitting on something.");
    return 1;
  }
  return this_player()->eventSit(target);
}

mixed do_sit_down_word_obj(string word, object target) {
  if(target->GetChair() ) {
    this_player()->eventPrint("You can't sit on " +target->GetShort()+ " while it's sitting on something.");
    return 1;
  }
  return this_player()->eventSit(target);
}
