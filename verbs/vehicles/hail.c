/*  Hail Caesar!  We who are about to die, Salute you!
 *  Or:  The hail verb
 *  Saryt
 */
#include <lib.h>
inherit LIB_VERB;

static void create() {
        ::create();
        SetVerb("hail");
        SetRules("STR STR");
        SetErrorMessage("Hail what <msg>?");
        SetHelp("Syntax:            hail <what> <msg>     \n"
                "Use this syntax to attempt to contact another "
                "ship.  Requires navigation skill and a set of "
                "ships navigation/communication equipment."
                );
}

mixed can_hail_str_str(string target, string msg) {
        object who = this_player();
        object ship = environment(who);

        if (!vehiclep(ship)) return "You need to do that from a ship.";
        if (this_player()->GetStaminaPoints() < 50) return "You're too tired.";
        return ship->CanHail(who, target);
}

mixed do_hail_str_str(string target, string message) {
        this_player()->AddStaminaPoints(-20);
        return environment(this_player())->eventHail(this_player(), target, message);
}

