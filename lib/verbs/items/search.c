/*    /verbs/items/search.c
 *    from the Dead Souls V Object Library
 *    created by Descartes of Borg 960121
 *    Version: @(#) search.c 1.2@(#)
 *    Last modified: 96/10/15
 */

/* Updated to take into account lightning conditions.
   -Melchezidek 2011-11-04
*/
/* Updated to stop taking into account inclement weather.
   -Mahkefel 2011-11-06
*/

#include <lib.h>
#include <daemons.h>
#include <function.h>
#include <vision.h>

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("search");
    SetRules("", "OBJ", "STR on OBJ", "STR of OBJ");
    SetErrorMessage("Search something?");
    SetHelp("Syntax: <search>\n"
            "        <search ITEM>\n"
            "        <search THING on ITEM>\n\n"
            "Without any arguments, this command allows you to search "
            "your general surroundings.  You may, however, concentrate "
            "your searching on any target.\n\n"
            "See also: listen, look, read, smell, touch");
}

mixed can_search() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
    if( !environment(this_player()) ) {
        return "You are nowhere.";
    }
    if( this_player()->GetEffectiveVision() == VISION_BRIGHT ) {
      return "It's too bright here to see fine detail.";
    }
    if( this_player()->GetEffectiveVision() == VISION_DARK ) {
      return "You can't make out fine detail in the dim light.";
    }
    if( this_player()->GetEffectiveVision() != VISION_CLEAR ) {
      return "You cannot see well enough to search.";
    }
    if(this_player()->GetBlind() > 0) {
        return "You are blind and cannot see to search!";
        }
    return 1;
}

mixed can_search_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
    if( this_player()->GetEffectiveVision() == VISION_BRIGHT ) {
      return "It's too bright here to see fine detail.";
    }
    if( this_player()->GetEffectiveVision() == VISION_DARK ) {
      return "You can't make out fine detail in the dim light.";
    }
    if( this_player()->GetEffectiveVision() != VISION_CLEAR ) {
      return "You cannot see well enough to search.";
    }
    if(this_player()->GetBlind() > 0) {
        return "You are blind and cannot see to search!";
        }

    return 1;
}

mixed can_search_str_word_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
   if( effective_light(this_player()) != 4 ) {
      return "You cannot see well enough to search.";
        }
    if(this_player()->GetBlind() > 0) {
        return "You are blind and cannot see to search!";
        }

    return 1;
}

mixed do_search() {
    mixed val = environment(this_player())->GetSearch();

    if( functionp(val) ) {
        if( !(functionp(val) & FP_OWNER_DESTED) ) {
            val = evaluate(val, this_player());
        }
        else {
            val = 0;
        }
    }
    if( !val ) {
        val = "You don't find a thing.";
    }
    environment(this_player())->eventPrint(this_player()->GetName() + " searches around.", this_player());
    this_player()->eventPrint(val);
    return 1;
}

mixed do_search_obj(object ob) {
    return ob->eventSearch(this_player());
}

mixed do_search_str_word_obj(string str, object ob) {
    return ob->eventSearch(this_player(), str);
}

