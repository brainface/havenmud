#include <lib.h>
inherit LIB_VERB;

static void create() {
  ::create();
  SetVerb("flee");
  SetRules("");
  SetHelp("Syntax:            \"flee\"\n\n"
          "Using this command will cause you to flee in blind panic. \n"
          "This command MAY be used while paralyzed, but does not remove the paralysis.");
}

mixed can_flee() {
  if (this_player()->GetSleeping()) {
    return "You are asleep!";
    }
  return 1;
}

int do_flee() {
  object env = environment(this_player());
  string dir, cmd;

  if (!env) { return 0; }
  cmd = this_player()->GetWimpyCommand() || "go out";
  if ( (sscanf(cmd, "go %s", dir) && !(env->GetExit(dir)) ) || (sscanf(cmd, "enter %s", dir) && !(env->GetEnter(dir)) )) {
    string *tmp;

    tmp = filter((string *)env->GetExits(), (: (string)!environment(this_player())->GetDoor($1) :) );
    if (!sizeof(tmp)) { /* No exits */
      tmp = filter((string *)env->GetEnters(), (: (string)!environment(this_player())->GetDoor($1) :) );
      if (!sizeof(tmp)) { /* And no enters */
        this_player()->eventPrint("You attempt to flee!");
        this_player()->eventPrint("There is no where to run to! Aaaaaahhhh!");
        return 0;
      }
      cmd = "enter " + tmp[random(sizeof(tmp))];
    }
   else cmd = "go " + tmp[random(sizeof(tmp))];
   }
  //debug(cmd);
  send_messages( ({ "scream", "run" }),
    "$agent_name $agent_verb like a nymph child and $agent_verb out of the area!",
      this_player(), 0, environment(this_player()) );
  return this_player()->eventForce(cmd);
}
      