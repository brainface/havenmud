/*    /verbs/items/free.c
 *    From the Dead Souls V Object Library
 *    A verb to allow people to free things from traps
 *    Creatd by Descartes of Borg 961010
 *    Version: @(#) free.c 1.1@(#)
 *    Last modified: 96/10/10
 */

#include <lib.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("free");
    SetRules("LIV from OBJ");
    SetSynonyms("release", "liberate", "emancipate");
    SetErrorMessage("Free what from what?");
    SetHelp("Syntax: <free OBJECT from OBJECT>\n\n"
	    "Frees an object from a trap.\n\n"
	    "Synonyms: emancipate, liberate, release\n\n"
	    "See also: capture");
}

mixed can_free_liv_from_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
    return 1;
}

mixed do_free_liv_from_obj(object target, object tool) {
    return tool->eventFree(this_player(), target);
}
