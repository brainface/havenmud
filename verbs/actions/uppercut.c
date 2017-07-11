#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("uppercut");
  SetRules("LIV", "");
  SetHelp("Causes you to throw an uppercut (a more deep, harmful punch) at a target.");
  SetStaminaCost(50);
  SetRequiredSkills( ([
    "melee combat" : 100,
    "brawling"     : 100,
    ]) );
}

mixed can_uppercut() {
  if (!this_player()->GetInCombat()) { return "Uppercut who?"; }
  return CanAction(this_player());
}

mixed can_uppercut_liv() {
  return CanAction(this_player());
}

mixed do_uppercut_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_uppercut() {
  return do_uppercut_liv(this_player()->GetCurrentEnemy());
}


int eventAttack(object who, object target) {
  int pro, con, result;
  string limb;
  int attacks = who->GetSkillLevel("melee combat")/50 + 1;
  
  pro = who->GetOffense( ({ "melee combat", "brawling" }) );
  
  con += target->GetDefense();
  con += target->GetStatLevel("agility")/10;
  con += target->GetLuck()/10;
    
  pro = random(pro); con = random(con);
 
  if (target->GetLimb("head")) limb = "head"; else limb = target->GetTorso();
    
  send_messages( ({ "lean", "attempt" }), 
    "$agent_name $agent_verb down a bit and $agent_verb to land an %^RED%^uppercut%^RESET%^ on $target_name!",
    who, target, environment(who));
  if (con > pro * 2) {
    send_messages( ({ "whiff" }), "$agent_name completely $agent_verb.", who, target, environment(who));
    return 1;
  }
  if (con > pro) {
    send_messages( ({ "manage" }), "$target_name $target_verb to dodge $agent_possessive_noun uppercut.", who, target, environment(who));
    return 1;
  }
  send_messages( ({ "land", }),
    "$agent_name $agent_verb a %^RED%^stunning uppercut%^RESET%^ on $target_possessive_noun " + limb + "!",
    who, target, environment(who));
  pro = who->GetDamage(who->GetSkillLevel("melee combat")/10, "brawling", target->GetDefense());
  attacks = attacks/2;
  if (!attacks) attacks = 1;
  if (attacks > 10) attacks = 10;
  pro = target->GetDamageInflicted(who, who->GetMeleeDamageType(), pro * attacks, 0, limb);
  target->eventInflictDamage(who, who->GetMeleeDamageType(), pro, 0, limb);
  if (!random(4)) {
    target->AddParalyzed(1);
    send_messages( ({ "are" }), "$target_name $target_verb %^BOLD%^RED%^stunned%^RESET%^ by the force of $agent_possessive_noun uppercut!",
        who, target, environment(target));
  }
  return 1;
}    
