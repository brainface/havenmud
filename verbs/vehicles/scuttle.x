#include <lib.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("scuttle");
  SetRules("STR", "");
  SetHelp("Syntax:     \"scuttle\" or \"scuttle ship\"\n\n"
          "Puts your ship onto the bottom."
          );
  SetErrorMessage("Scuttle the ship?");
}

mixed can_scuttle() {
  object env = environment(this_player());
  if (!vehiclep(env)) return "You can only scuttle ships.";
  return env->CanScuttle(this_player());
}

mixed can_scuttle_str(string what) {
  if (what != "ship") return "Scuttle what?";
  return can_scuttle();
}

mixed do_scuttle() {
  object env = environment(this_player());
  env->eventScuttle(this_player());
  return 1;
}

mixed do_scuttle_str(string what) {
  return do_scuttle();
}

  