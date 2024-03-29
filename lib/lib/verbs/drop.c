/*    /lib/drop.c
 *    From the Dead Souls V Object Library
 *    Makes an object something which can be dropped
 *    Created by Descartes of Borg 960113
 *    Version: @(#) drop.c 1.2@(#)
 *    Last modified: 96/12/22
 */

#include <function.h>

private mixed PreventDrop = 0;

// abstract methods
string GetDefiniteShort();
mixed eventMove(mixed dest);
// end abstract methods

mixed GetPreventDrop() {
    return PreventDrop;
}

mixed SetPreventDrop(mixed val) {
    if(!intp(val) && !stringp(val) && !functionp(val) && !objectp(val) ) {
	error("Bad argument 1 to SetPreventDrop().\n");
    }
    return (PreventDrop = val);
}

mixed CanDrop(object who) {
    if( !PreventDrop ) {
	return 1;
    }
    if( intp(PreventDrop) ) {
	return 0;
    }
    if( stringp(PreventDrop) ) {
	return PreventDrop;
    }
    if( objectp(PreventDrop) ) {
	if( PreventDrop == who ) {
	    return capitalize(GetDefiniteShort()) +
		" simply will not leave your grasp.";
	}
	else {
	    return 1;
	}
    }
    else {
	if( functionp(PreventDrop) & FP_OWNER_DESTED ) {
	    return "There is a problem with a functional.";
	}
	return evaluate(PreventDrop, who);
    }
}

mixed eventDrop(object who) {
    mixed tmp;
    
    if( who != environment() ) {
	return 0;
    }
    tmp = eventMove(environment(who));
    if( !tmp ) {
	who->eventPrint("Something prevents you from dropping "
			+ GetDefiniteShort() + ".");
	return 1;
    }
    if( tmp != 1 ) {
	return tmp;
    }
    send_messages("drop", "$agent_name $agent_verb $target_name.",
		  who, this_object(), environment(who));
    return 1;
}

mixed direct_drop_obj(object target) {
    if( environment() != this_player() ) {
	return "#You don't have that to drop.";
    }
    return CanDrop(this_player());
}
