#include <lib.h>
#include <rounds.h>
#include <position.h>
inherit LIB_VERB;
mixed can_disarm_liv(object);
mixed do_disarm_liv(object);
int eventDisarm(object who, object target);

static void create() {
  verb::create();
  SetVerb("disarm");
  SetRules("", "LIV");
  SetErrorMessage("Disarm whom?");
  SetHelp( "Syntax: \"disarm LIV\"  \n\n"
           "Makes an attempt to disarm a living target.\n"
           "Requires the \"disarm\" skill."
           );
}


mixed can_disarm() {
  if (!(this_player()->GetInCombat())) { return "Disarm whom?"; }
  return can_disarm_liv(this_player()->GetCurrentEnemy());
}

mixed can_disarm_liv(object target) {
  object who = this_player();
  int cost = 100 - who->GetSkillLevel("disarm");
  if (who->GetSleeping()) { return "While sleeping?"; }
  if (who->GetParalyzed()) { return "You cannot move."; }
  if (!(sizeof(who->GetWielded()) ) ) {
    return "You cannot disarm while unarmed!"; }
  if (!(who->GetPosition() == POSITION_STANDING)) { 
    return "You must be standing up!"; }
  if (who->GetSkillLevel("disarm") < 1) 
    return "You aren't familiar with that tactic.";
  if (cost < 10) cost = 10;
  if (who->GetStaminaPoints() < cost) {
    return "You are too tired to disarm anyone."; }
  if (environment(who)->GetProperty("no attack")) {
    return "Divine forces prevent your action.";
    }
 if (who->GetCombatStyle()) { return "You cannot do that while using a combat style."; }
 return 1;
}

mixed do_disarm() {
   return do_disarm_liv(this_player()->GetCurrentEnemy());
   }

mixed do_disarm_liv(object target) {
  int cost = 100 - this_player()->GetSkillLevel("disarm");
  if (cost < 10) cost = 10;
  if (!target) {
    this_player()->eventPrint("No target?");
    return 1;
  }
  this_player()->AddStamina(-cost);
  this_player()->SetAttack(target, (: eventDisarm( $(this_player()), $(target)) :), ROUND_WEAPON);
  send_messages( ({ "attempt" }),
     "$agent_name%^GREEN%^ $agent_verb%^RESET%^ to disarm $target_name!",
      this_player(), target, environment(target));
  return 1;
}
 
 
int eventDisarm(object who, object target) { 
  object *target_wpns = target->GetWielded();
  int num_target_wpns = sizeof(target_wpns);
  object rnd_wpn;
  int defender, attacker;
  
  if (sizeof(target_wpns)) { rnd_wpn = target_wpns[random(num_target_wpns)]; }
  if (!rnd_wpn) {
    who->eventPrint("But " + target->GetCapName() + " is not wielding any weapons!");
    return 1;
    }
  if (!rnd_wpn->CanDisarm(who, target)) {
    who->eventPrint("Something prevents " + possessive_noun(target) + " from being disarmed!");
    return 1;
    }
  attacker = who->GetSkillLevel("disarm");
  defender = target->GetDefense();
  if (environment(target) != environment(who)) return 0;
  if (random(attacker) > defender) {
    send_messages("disarm", "$agent_name%^BOLD%^GREEN%^ $agent_verb%^RESET%^ $target_name!", who, target, environment(who) );
    rnd_wpn->eventUnequip(target);
    rnd_wpn->eventDrop(target);
    return 1;
  }
   send_messages("fail", "$agent_name%^RED%^ $agent_verb%^RESET%^ to disarm $target_name.", who, target, environment(who) );
   return 1;
}
