/*    /verbs/items/pull.c
 *    from the Dead Souls V Object Library
 *    created by Descartes of Borg 960114
 *    Version: @(#) pull.c 1.3@(#)
 *    Last modified: 96/10/18
 */

#include <lib.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("pull");
    SetRules("OBJ", "STR on OBJ");
    SetErrorMessage("Pull what? Or pull what on what?");
    SetHelp("Syntax: <pull OBJECT>\n"
	    "        <pull THING on OBJECT>\n\n"
	    "Allows you to pull an object, or perhaps a thing on the "
	    "object.  For example, you might want to "
	    "\"pull lever on the wall\", or simply \"pull lever\".\n\n"
     );
}

mixed can_pull_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
    return 1;
}

mixed can_pull_str_on_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
    return 1;
}

mixed do_pull_obj(object target) {
    return target->eventPull(this_player());
}

varargs mixed do_pull_str_on_obj(string thing, object target) {
    return target->eventPull(this_player(), remove_article(lower_case(thing)));
}
