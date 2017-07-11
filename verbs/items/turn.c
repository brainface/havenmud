/*    /verbs/items/turn.c
 *    modified version of touch - mel 2017
 *    from the Dead Souls V Object Library
 *    created by Descartes of Borg 961014
 *    Version: @(#) turn.c 1.1@(#)
 */

#include <lib.h>
#include <daemons.h>
#include <function.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("turn");
    SetRules("OBJ", "STR on OBJ", "STR of OBJ");
    SetErrorMessage("Turn something?");
    SetHelp("Syntax: <turn ITEM>\n"
            "        <turn THING on ITEM>\n\n"
            "This command allows you to turn an object such as a knob.\n\n"
            "See also: listen, look, read, search, smell");
}

mixed can_turn_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
    return 1;
}


mixed can_turn_str_word_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
    return 1;
}

mixed do_turn_obj(object ob) {
    return ob->eventTurn(this_player());
}

mixed do_turn_str_word_obj(string str, object ob) {
    return ob->eventTurn(this_player(), str);
}
