#include <lib.h>
#include <damage_types.h>
#include <vision.h>
inherit LIB_ACTION;

static void create() {
  ::create();
  SetVerb("headbutt");
   SetRules("LIV", "");

  SetHelp("Causes you to headbutt someone.  Does only minor damage, but often stuns opponents.");
  SetStaminaCost(25);
  SetRequiredSkills( ([
    "brawling"     : 50,
    "melee combat" : 50,
    ]) );
}

mixed can_headbutt() {
  if (!this_player()->GetInCombat()) { return "Headbutt who?"; }
  return CanAction(this_player());
}

mixed can_headbutt_liv() {
  return CanAction(this_player());
}

mixed do_headbutt_liv(object target) {
  return eventAction(this_player(), target);
}

mixed do_headbutt() {
  return do_headbutt_liv(this_player()->GetCurrentEnemy());
}


int eventAttack(object who, object target) {
  int pro, con, result;
  string limb;
  int attacks = who->GetSkillLevel("melee combat")/50 + 1;
  
  pro = who->GetOffense( ({ "melee combat", "brawling" }) );
  con = target->GetDefense();
  con += target->GetStatLevel("agility")/10;
  con += target->GetLuck()/10;
    
  pro = random(pro); con = random(con);
 
  if (target->GetLimb("head")) limb = "head";
  if (limb != "head") {
    send_messages( ({ "ponder", "find", "has" }),
      "$agent_name $agent_verb headbutting $target_name, but $agent_verb that $target_name $target_verb no head!",
      who, target, environment(who));
    return 1;
  }
  if (pro * 2 < con) result = 0;
    else if (pro < con) result = 1;
  if (pro > con) result = 2;
    
  if (!result) {
      send_messages("miss", "$agent_name $agent_verb $target_name with $agent_possessive headbutt.", who, target, environment(who));
      return 1;
    }
    if (result == 1) {
      send_messages("dodge", "$target_name $target_verb $agent_possessive_noun headbutt.", who, target, environment(who));
      return 1;
  }
  send_messages("headbutt", "$agent_name%^GREEN%^ $agent_verb%^RESET%^ $target_name.", who, target, environment(who));
  pro = who->GetDamage(who->GetSkillLevel("melee combat")/10, "brawling", target->GetDefense());
  pro = target->GetDamageInflicted(who, who->GetMeleeDamageType(), pro, 0, limb);
  target->eventInflictDamage(who, who->GetMeleeDamageType(), pro, 0, limb);
  result = who->GetSkillLevel("brawling")/50;
  if (result > 6) result = 6;
  if (!random(result)) target->AddParalyzed(result);
  return 1;
}
