#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("punch");
  SetRules("LIV", "");
  SetHelp("Unleashes a series of punches against a target equal to your normal full round of attacks.");
  SetStaminaCost(5);
  SetRequiredSkills( ([
    "melee combat" : 10,
    "brawling"     : 1,
    ]) );
}

mixed can_punch() {
  if (!this_player()->GetInCombat()) { return "Punch who?"; }
  return CanAction(this_player());
}

mixed can_punch_liv() {
  return CanAction(this_player());
}

mixed do_punch_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_punch() {
  return do_punch_liv(this_player()->GetCurrentEnemy());
}

int eventAttack(object who, object target) {
  int pro, con, result;
  string limb; 
  /* for the purposes of this test, I'm going easy. */
  int attacks = 1;
  attacks += who->GetSkillLevel("brawling")/50;
  attacks += who->GetSkillLevel("melee combat")/50;
  if (attacks > 10) attacks = 10;
  while(attacks) {
    if (!target) break;           
    if (target->GetDying()) break;

    pro = who->GetOffense( ({ "melee combat", "brawling" }) );
    con += target->GetDefense();
    con += target->GetStatLevel("agility")/10;
    con += target->GetLuck()/10;
    
    pro = random(pro); con = random(con);
    limb = target->GetRandomLimb();
    if (pro * 2 < con) result = 0;
      else if (pro < con) result = 1;
    if (pro > con) result = 2;
    
    if (!result) {
      send_messages("miss", "$agent_name $agent_verb $target_name with $agent_possessive punch.", who, target, environment(who));
      attacks--;
      continue;
    }
    if (result == 1) {
      send_messages("dodge", "$target_name $target_verb $agent_possessive_noun punch.", who, target, environment(who));
      attacks--;
      continue;
  }
  send_messages("punch", "$agent_name $agent_verb $target_name in the " + limb +".", who, target, environment(who));
  pro = who->GetDamage(who->GetSkillLevel("melee combat")/10, "brawling", target->GetDefense());
  pro = target->GetDamageInflicted(who, who->GetMeleeDamageType(), pro, 0, limb);
  target->eventInflictDamage(who, who->GetMeleeDamageType(), pro, 0, limb);
  attacks--;
  }
  return 1;
}
  
