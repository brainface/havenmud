/*    /verbs/players/lie.c
 *    from the Dead Souls V Object Library
 *    created by Descartes of Borg 960711
 *    Version: @(#) lie.c 1.4@(#)
 *    Last Modified: 96/12/21
 */

#include <lib.h>
#include <position.h>
#include <rounds.h>
#include <conditions.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("lie");
    SetRules("down", "in OBJ", "down in OBJ", "on OBJ", "down on OBJ");
    SetErrorMessage("Lie down?");
    SetSynonyms("lay");
    SetHelp(
      "Syntax: <lie down>\n"
      "                <lie down in [object]>\n\n"
      "Allows you to lie down on the ground or in a bed. "
      "It can be really exciting and increases your rate of "
      "regenerating hp, mp, and sp.\n\n"
      "Synonyms: lay (bad english)\n\n"
      "See also: sit, sleep, stand"
    );
}

mixed can_lie_down() {
   if( this_player()->GetParalyzed() ) {
	    return "You cannot do anything.";
   }
   if(this_player()->GetSleeping()) {
      return "You cannot do that while sleeping!";
   }
   if( this_player()->GetPositiion() == POSITION_LYING) {
	   return "You are already lying down!";
   }
   if( this_player()->GetConditionFlag(CONDITION_PREVENT_POSITION)) {
     return "Your legs refuse to bend!";   
   }
   return 1;
}

mixed can_lie_word_obj() {
    return can_lie_down();
}

mixed can_lie_down_word_obj() {
    return can_lie_down();
}

mixed do_lie_down() {
    return this_player()->eventLay();
}

mixed do_lie_word_obj(string word, object target) {
    return this_player()->eventLay(target);
}

mixed do_lie_down_word_obj(string word, object target) {
    return this_player()->eventLay(target);
}
