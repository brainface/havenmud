/*    /verbs/items/climb.c
 *    from the Dead Soulsr2 Object Library
 *    climb WRD OBJ
 *    created by Descartes of Borg 951018
 *    Version: @(#) climb.c 1.3@(#)
 *    Last modified: 96/10/20
 */

#pragma save_binary

#include <lib.h>
#include <climb.h>

inherit LIB_VERB;

mixed do_climb_word_obj(string word, object ob);

static void create() {
    verb::create();
    SetVerb("climb");
    SetErrorMessage("Climb up or down what?");
    SetRules("up OBJ", "down OBJ", "out of OBJ", "out OBJ", "into OBJ",
	     "in OBJ", "through OBJ", "OBJ");
    SetHelp("Syntax: <climb OBJECT>\n"
	    "        <climb up OBJECT>\n"
	    "        <climb down OBJECT>\n"
	    "        <climb out of OBJECT>\n"
	    "        <climb into OBJECT>\n"
	    "        <climb through OBJECT>\n\n"
	    "Allows you to use another object to climb down or out of an "
	    "area.\n\n"
	    "See also: enter, go, jump");
}

mixed can_climb_obj() { 
  if (this_player()->GetSleeping()) return "You are asleep!";
    if( this_player()->GetParalyzed() ) {
	return "You cannot do anything!";
    }
    return 1;
}

mixed can_climb_word_obj() {
    return can_climb_obj();
}

mixed can_climb_out_of_obj() {
    return can_climb_obj();
}

mixed do_climb_obj(object ob) {
    return do_climb_word_obj("up", ob);
}

mixed do_climb_word_obj(string word, object ob) {
    int type;

    switch(word) {
        case "up": type = CLIMB_UP; break;
        case "down": type = CLIMB_DOWN; break;
        case "out": type = CLIMB_OUT; break;
        case "in": case "into": type = CLIMB_INTO; break;
        case "through": type = CLIMB_THROUGH;
        default: type = CLIMB_UP; break;
    }
    return ob->eventClimb(this_player(), type);
}

mixed do_climb_out_of_obj(object ob) {
    return do_climb_word_obj("out", ob);
}
