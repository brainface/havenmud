#include <lib.h>
inherit LIB_VERB;

static void create() {
  verb::create();
  SetVerb("dive");
  SetRules("WRD", "into OBJ");
  SetErrorMessage("Dive into what, or dive where?");
  SetHelp(
    "Syntax:  \"dive WRD\", \"dive into OBJ\" \n\n"
     "Allows the agent to dive somewhere.  \n"
    "Examples:  dive underwater, dive into pool"
   );

 }

mixed can_dive_wrd() {
  if (this_player()->GetParalyzed()) {
     return "You cannot move!";
    }
  return 1;
 }

mixed can_dive_into_obj() {
  if (this_player()->GetParalyzed()) {
     return "You cannot move!";
    }
  return 1;
  }

mixed do_dive_wrd(string args) {
  if (environment(this_player())->GetDive(args)) {
   return (environment(this_player())->eventDive(this_player(), args));
   }
  message("my_action",
     "You dive " + args + ".",
      this_player() );
  message("other_action",
    this_player()->GetCapName() + " dives " + args + ".",
    environment(this_player()), this_player() );
  return 1;
  }

mixed do_dive_into_obj(object target) {
  message("my_action",
    "You dive into "+ target->GetShort() + ".",
     this_player() );
  message("other_action",
     this_player()->GetCapName() + " dives into " + target->GetShort() + ".",
     environment(this_player()), this_player() );
  target->eventExecuteDive(this_player());
  return 1;
  }
