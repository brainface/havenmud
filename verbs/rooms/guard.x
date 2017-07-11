/* Guard Verb
 *  For blocking things.
 */
#include <lib.h>
#include <std.h>
inherit LIB_VERB;

mixed can_guard_str(string);
mixed do_guard_str(string);

static void create() {
  ::create();
  SetNoClean(1);
  SetVerb("guard");
  SetErrorMessage("Guard who or which direction?");
  SetRules("STR", "LIV");
}

mixed can_guard_str(string dir) {
  string *ex_en = ({ });

  if(!environment(this_player()) ) 
    return "You are so screwed.";

  ex_en += environment(this_player())->GetExits();
  ex_en += environment(this_player())->GetEnters();

  
  if (this_player()->GetProperty("guarding")) {
    return "You can only guard one location at a time!";
  }
  if (this_player()->GetSleeping()) {
    return "You cannot do that while sleeping!";
  }
  if (immortalp(this_player())) { 
    return "That's not fair!"; 
  }
  if (member_array(dir, ex_en) == -1) { 
    return "You cannot block that!";
    }
  if (environment(this_player())->GetProperty("no block")) {
    return "Something stops you from doing that.";
    }
  if (this_player()->GetParalyzed()) {
    return "It is hard to block when you cannot move!";
    }
  if (this_player()->GetInCombat()) {
    return "You are far too busy right now!";
    }
  return 1;
}

mixed can_guard_liv() {
  if (this_player()->GetParalyzed()) {
    return "It is hard to block when you cannot move!";
  }
  if (this_player()->GetSleeping()) {
    return "You cannot do that while sleeping!";
  }
  if (environment(this_player())->GetProperty("no block")) {
    return "Something stops you from doing that.";
  }
  return 1;
}

mixed do_guard_str(string dir) {
  object guard;
  object who = this_player();

  if(!guard = new(STD_OBJ "guard_obj")) {
    return "Something is wrong with the guard object.";
    }
  this_player()->SetProperty("guarding", guard);
  guard->eventMove(environment(who));
  guard->SetOwner(who);
  guard->SetBlocking(dir);
  send_messages("start",
    "$agent_name $agent_verb to guard the " + dir + ".",
      who, 0, environment(who));
  return 1;
  }

mixed do_guard_liv(object target) {
  send_messages("begin",
    "$agent_name $agent_verb to guard $target_name.",
    this_player(), target, environment(target) );
  target->SetGuard(this_player());
  this_player()->SetProperty("guarding", target);
  return 1;
}

string GetHelp(string useless) {
  return "Syntax:  guard STR\n\n"
          "Allows a person to guard a direction, person or building.\n"
          "See also:  stop ";
  }
