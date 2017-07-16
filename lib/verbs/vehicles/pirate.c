#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("pirate");
  SetRules("STR", "");
  SetHelp("Syntax:     \"pirate\" or \"pirate ship\"\n\n"
          "Take control over a ship. This only works when the "
          "captain and owner are not around."
          );
  SetErrorMessage("Pirate the ship?");
}

mixed can_pirate() {
  object env = environment(this_player());
  if (!vehiclep(env)) return "You can only pirate ships.";
  return env->CanPirate(this_player());
}

mixed can_pirate_str(string what) {
  if (what != "ship") return "Pirate what?";
  return can_pirate();
}

mixed do_pirate() {
  object env = environment(this_player());
  env->eventPirate(this_player());
  VEHICLES_D->AddShip(env);
  return 1;
}

mixed do_pirate_str(string what) {
  return do_pirate();
}

  