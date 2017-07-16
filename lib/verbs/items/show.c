/* show.c
 * show <obj> to <player>
 * show <obj> off
 * displays long description of item in inventory to others in room
 */

#include <lib.h>
#include <daemons.h>
#include "include/look.h"

inherit LIB_VERB;

static void create() {
    verb::create();
    SetVerb("show");
    SetRules("OBJ", "OBJ to LIV");
    SetErrorMessage("Show something to someone?");
    SetHelp("Syntax: <show ITEM to LIV>\n"
            "You can show off an item you are carrying or wearing "
            "to a specific person. The target will see a detailed "
            "description of the item.\n"
            "See also: look");
}

mixed can_show_obj_to_liv(string verb, string id, string living) {
   if( !environment(this_player()) ) return "You are nowhere.";
   if(this_player()->GetSleeping()) return "You cannot do that while sleeping!";
   return 1;
}

mixed do_show_obj_to_liv(object ob, object living) {

    if ( environment(ob) != this_player()) return "You don't have that!";
    if (!this_player()->GetInvis()) {
      send_messages("show", "$agent_name $agent_verb off $agent_possessive_noun "
        + ob->GetKeyName() + " to $target_name.",
        this_player(), living, environment(this_player()));
    } else {
      environment(this_player())->eventPrint("A shadowy blur " +
      "displays a " + ob->GetKeyName()+" to "+living->GetKeyName()+".");
    }
    if(effective_light(this_player()) < -1) {
      living->eventPrint("You see the vague outline of something held near your "
        "eyes, but you can't quite see well enough to make it out.");
    } else {
      ob->eventShow(living);
    }

    return 1;
}

