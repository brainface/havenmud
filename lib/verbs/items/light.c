/*    /verbs/items/light.c
 *    from the Dead Souls Object Library
 *    a command for lighting things which can be lit
 *    created by Descartes of Borg 960512
 */

#include <lib.h>
#include "include/light.h"

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("light");
    SetSynonyms( ({ "burn" }) );
    SetRules("OBS", "OBS with OBJ");
    SetErrorMessage("Light what?  Or light what with what?");
    SetHelp("Syntax: <light OBJECT>\n"
	    "        <light OBJECT with OBJECT>\n\n"
	    "Using the first syntax, you can light things which "
	    "do not need another source in order to be lit, like a lamp or "
	    "a lighter.  The second syntax allows you to light objects which "
	    "require burning sources in order for themselves to be light, "
	    "like a torch or a camp fire.\n\n"
	    "See also: extinguish, strike");
}

mixed can_light_obj() {
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
    return 1;
}

mixed can_light_obj_with_obj() {
    int light;
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
    
    if( (light = effective_light(this_player())) < 0 ) {
	if( 100 + (10*light) < random(100) )
	  return "You fumble around in the darkness.";
	else return 1;
    }
    else if( light > 4 ) {
	if( 100 - (10*light) < random(100) )
	  return "You fumble around in the blinding light.";
	else return 1;
    }
    else return 1;
}

mixed do_light_obj(object target) {
    return do_light_obs(({ target }));
}

mixed do_light_obj_with_obj(object target, object source) {
    return do_light_obs_with_obj(({ target }), source);
}

mixed do_light_obs(mixed *targs) {
    object *obs;
    string tmp;
    
    if( !sizeof(targs) ) {
        this_player()->eventPrint("There is no such thing to be lit.");
	return 1;
    }
    obs = filter(targs, (: objectp :));
    if( !sizeof(obs) ) {
        mixed *ua;

	ua = unique_array(targs, (: $1 :));
	foreach(string *list in ua) this_player()->eventPrint(list[0]);
	return 1;
    }
    obs = filter(obs, (: (int)$1->eventLight(this_player()) :));
    if( !sizeof(obs) ) return 1;
    tmp = item_list(obs);
    this_player()->eventPrint("You light " + tmp + ".");
    environment(this_player())->eventPrint((string)this_player()->GetName() +
					   " lights " + tmp + ".",
					   this_player());
    return 1;
}

mixed do_light_obs_with_obj(mixed *targs, object source) {
    object *obs;
    string tmp;
    
    if( !sizeof(targs) ) {
        this_player()->eventPrint("There is no such thing to be lit.");
	return 1;
    }
    obs = filter(targs, (: objectp :));
    if( !sizeof(obs) ) {
        mixed *ua;

	ua = unique_array(targs, (: $1 :));
	foreach(string *list in ua) this_player()->eventPrint(list[0]);
	return 1;
    }
    obs = filter(obs, (: (int)$1->eventLight(this_player(), $(source)) :));
    if( !sizeof(obs) ) return 1;
    tmp = item_list(obs);
    this_player()->eventPrint("You light " + tmp + " with " +
			      (string)source->GetShort() + ".");
    environment(this_player())->eventPrint((string)this_player()->GetName() +
					   " lights " + tmp + " with " +
					   (string)source->GetShort() + ".",
					   this_player());
    return 1;
}
