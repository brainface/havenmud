/*    /verbs/players/sing.c
 *    From Dead Souls LPMud
 *    Created by Descartes of Borg 951027
 *    Version: @(#) sing.c 1.4@(#)
 *    Last modified: 96/12/16
 */

#include <lib.h>
#include <daemons.h>
#include <conditions.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("sing");
    SetRules("STR", "STR to OBJ", "STR to STR", "STR to STR of OBJ",
	     "STR against STR");
  SetErrorMessage("Sing what to what?");
    SetHelp("Syntax: <sing SPELL>\n"
	    "        <sing SPELL to LIMB>\n"
	    "        <sing SPELL against STRING>\n"
	    "        <sing SPELL to TARGET>\n"
	    "        <sing SPELL to LIMB of TARGET>\n\n"
	    "Allows you to sing any song using whatever syntax the "
	    "song in question requires.  To heal someone, for example, "
            "\"sing heal on descartes\".  \n"
     );
}

mixed can_sing_str(string song) {
  object tmp = SONGS_D->GetSong(song);
  
  if( tmp ) {
    string verb = tmp->GetVerb();
    if( verb != "sing" ) {
      return "That is not a song you sing.";
    }
  }
  if(this_player()->GetSleeping()) {
    return "You cannot do that while sleeping!";
  }
  if(this_player()->GetConditionFlag(CONDITION_PREVENT_MAGIC)) { 
    return "Something prevents you from using magic";
  }
  if(this_player()->GetConditionFlag(CONDITION_PREVENT_TALK)) {
    return "Something prevents you from speaking"; 
  }   
  return this_player()->CanSing(tmp);
}

mixed can_sing_str_to_obj(string song) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    return can_sing_str(song);
}

mixed can_sing_str_to_str(string song) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    return can_sing_str(song);
}

mixed can_sing_str_against_str(string song) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    return can_sing_str(song);
}

mixed can_sing_str_to_str_of_str(string song) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    return can_sing_str(song);
}

mixed do_sing_str(string song) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    return this_player()->eventPrepareSong(song);
}

mixed do_sing_str_to_obj(string song, object target) {
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
    return this_player()->eventPrepareSong(song, target);
}

mixed do_sing_str_against_str(string song, object target) {
    return this_player()->eventPrepareSong(song, target);
}

mixed do_sing_str_to_str(string song, string limb) {
    return this_player()->eventPrepareSong(song, limb);
}

mixed do_sing_str_to_str_of_obj(string song, string limb, object target) {
    return this_player()->eventPrepareSong(song, limb, target);
}
