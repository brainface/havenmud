#include <lib.h>
#include <daemons.h>
#include <function.h>

inherit LIB_VERB;

static void create() {
   verb::create();
   SetVerb("spin");
   SetRules("OBJ");
   SetErrorMessage("Spin what?");
   SetHelp("Syntax:  <spin ITEM>\n\n"
           "Used for spinning things around, like tops.");
}

mixed can_spin_obj() {
   return 1;
}

mixed do_spin_obj(object ob) {
   return ob->eventSpin(this_player());
}
