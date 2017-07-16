#include <lib.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("greet");
  SetRules("LIV");
  SetErrorMessage("Greet who?");
  SetHelp("Syntax:   <greet LIVING>\n\n"
          "Greets a target.  Good for getting NPCs to talk to you.");
}

mixed can_greet_liv() {
  if (this_player()->GetSleeping()) return "You dream of someday greeting people.";
  if (this_player()->GetParalyzed()) return "You'd wave in greeting... if only you could move.";
  return 1;
}

mixed do_greet_liv(object target) {
  if (target == this_player()) {
    this_player()->eventPrint("You warmly greet yourself.");
    return 1;
  }
  send_messages( ({ "greet" }), "$agent_name $agent_verb $target_name.", this_player(), target, environment(this_player()));
  target->eventGreet(this_player());
  return 1;
}