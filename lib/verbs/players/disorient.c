#include <lib.h>
#include <rounds.h>
#include <position.h>
#include <conditions.h>
inherit LIB_VERB;
mixed can_disorient_liv(object);
mixed do_disorient_liv(object);
int eventDisorient(object who, object target);

static void create() {
  verb::create();
  SetVerb("disorient");
  SetRules("", "LIV");
  SetErrorMessage("Disorient whom?");
  SetHelp( "Syntax: \"disorient LIV\"  \n\n"
           "Makes an attempt to, rather than inflict damage, disorient a living target.\n"
           "Requires the \"disorient\" skill."
           );
}


mixed can_disorient() {
  if (!(this_player()->GetInCombat())) { return "Disorient whom?"; }
  return can_disorient_liv(this_player()->GetCurrentEnemy());
}

mixed can_disorient_liv(object target) {
  object who = this_player();
  int cost = 30 - who->GetSkillLevel("disorient");
  if (who->GetSleeping()) { return "While sleeping?"; }
  if (who->GetParalyzed()) { return "You cannot move."; }
  if (!(who->GetPosition() == POSITION_STANDING)) { 
    return "You must be standing up!"; }
  if (who->GetSkillLevel("disorient") < 1) 
    return "You aren't familiar with that tactic.";
  if (cost < 5) cost = 5;
  if (who->GetStaminaPoints() < cost) {
    return "You are too tired to disorient anyone."; }
  if (environment(who)->GetProperty("no attack")) { return "Divine forces prevent your action."; }
  if (who->GetConditionFlag(CONDITION_PREVENT_COMBAT)) {
    return "Something prevents you from fighting";}   
  if (who->GetCombatStyle()) { return "You cannot do that while using a combat style."; }
  return 1;
}

mixed do_disorient() {
   return do_disorient_liv(this_player()->GetCurrentEnemy());
}

mixed do_disorient_liv(object target) {
  int cost = 30 - this_player()->GetSkillLevel("disorient");
  if (cost < 5) cost = 5;
  if (!target) {
    this_player()->eventPrint("Disorient whom?");
    return 1;
  }
  this_player()->AddStamina(-cost);
  this_player()->SetAttack(target, (: eventDisorient( $(this_player()), $(target)) :), ROUND_OTHER);
  send_messages( ({ "attempt" }),
     "$agent_name%^GREEN%^ $agent_verb%^RESET%^ to disorient $target_name!",
      this_player(), target, environment(target));
  return 1;
}
 
 
int eventDisorient(object who, object target) { 
   int attack  = who->GetSkillLevel("disorient");
   if (!target) return 0;
   if (environment(target) != environment(who)) return 0;
   send_messages("attempt", "$agent_name $agent_verb to %^BLUE%^disorient%^RESET%^ $target_name.", who, target, environment(who) );
   target->AddRecoveryTime(attack);
   return 1;
}
