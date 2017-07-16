/*    /lib/digging.c
 *    from the Nightmare IVr2 Object Library
 *    handles functions to allow something to dig
 *    created by Descartes of Borg 951030
 */

#include "include/digging.h"
#include <function.h>

static void create() { /* stub in case future functionality is needed */ }

mixed indirect_bury_obj_with_obj() {
    if( environment() != this_player() ) return 0;
    return 1;
}

mixed direct_dig_with_obj() {
    if( environment() != this_player() ) return 0;
    return 1; 
}

mixed indirect_dig_obj_with_obj(string id) { 
    if( environment() != this_player() ) return 0;
    return 1;
}

mixed direct_mine_with_obj() {
  return 1;
}

mixed direct_farm_with_obj() {
  return 1;
}


mixed eventBury(object who, string what) {
    string tmp;

    tmp = (mixed)environment(who)->eventBury(who, this_object(), what);
    if( tmp ) return tmp;
    else message("my_action", "Burying did not work too well.", who);
    return 1;
}

varargs mixed eventDig(object who, string what) {
    mixed tmp;

    tmp = (mixed)environment(who)->eventDig(who, this_object(), what);
    if( tmp ) return tmp;
    else message("my_action", "Digging did not work too well.", who);
    return 1;
}

varargs mixed CanBuryWith(object who, object what) {
    int fp = functionp(environment(who)->GetBury());

    if( !fp || (fp & FP_OWNER_DESTED) ) {
	return "This is not a very good place for burying.";
    }
    return 1;
}

varargs mixed CanDigWith(object who, object what) {
    if( what ) { // the parser will trigger CanDig() there
	return 1;
    }
    else {
	int fp = functionp(environment(who)->GetDig());

	if( !fp || (fp & FP_OWNER_DESTED) ) {
	    return "This is not a very good place for that kind of digging.";
	}
	return 1;
    }
}

mixed eventBuryWith(object who, object what) {
    mixed tmp = environment(who)->eventBuryItem(who, this_object(), what);

    if( tmp == 1 ) {
	return tmp;
    }
    else {
	who->eventPrint(tmp || "The burial did not work well.");
    }
    return 1;
}

varargs mixed eventDigWith(object who, object what) {
    object target;
    mixed tmp;

    if( what ) {
	target = what;
    }
    else {
	target = environment(who);
    }
    tmp = target->eventDig(who, this_object());
    if( tmp == 1 ) {
	return tmp;
    }
    else {
	who->eventPrint(tmp || "The digging did not work so well.");
	return 1;
    }
}

