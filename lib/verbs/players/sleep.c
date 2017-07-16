#include <lib.h>
#include <position.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("sleep");
  SetRules("");
  SetHelp(
    "Syntax: <sleep>\n\n"
    "Use of this verb causes a character to sleep. "
    "Sleep increases the speed at which you regenerate "
    "hp, mp and sp. Once asleep, you will wake after a random "
    "amount of time, or if another character wakes you.\n\n"
    "See also: lie, sit, wake"
  );
}

mixed can_sleep() { 
  if (this_player()->GetInCombat()) {
    return "Aren't you a bit busy for that?";
    }
   if(this_player()->GetSleeping()) {
      return "You are already asleep!";
   }
  if (this_player()->GetPosition() != POSITION_LYING) {
    return "You must be lying down to do that.";
    }
  if (environment(this_player())->GetProperty("shallows") || environment(this_player())->GetProperty("ocean")) {
    return "You can't sleep in the water!";
  }
  return 1;
}

mixed do_sleep() {
  this_player()->SetSleeping(random(3) + 2);
  send_messages("drift", 
    "$agent_name $agent_verb into a sound sleep.", 
    this_player(), 0, environment(this_player()) );
  return 1;
}
