/* Backstab
 * Rewritten to not suck
 * 11/02/2007
 * Duuk@Haven
 */

#include <lib.h>
#include <position.h>
#include <conditions.h>
inherit LIB_VERB;

int eventBackstab(object, object);

static void create() {
  verb::create();
  SetVerb("backstab");
  SetRules("LIV");
  SetErrorMessage("Backstab who?");
  SetHelp(
    "Syntax: backstab TARGET\n\n"
    "A brutally effective first-strike on a target... if it works. \n"
    "A nasty way to get yourself killed... if it doesn't.\n"
    "It is a more effective attack with a knife or bow, but a sneak \n"
    "attack with a giant axe is still best avoided."
  );
}

mixed can_backstab_liv() {
  if (!environment(this_player()) )
     return "You're totally screwed.";
  if (this_player()->GetPosition() == POSITION_SITTING || this_player()->GetPosition() == POSITION_LYING)
      return "You cannot attack in that position!";
  if (this_player()->GetSleeping())
      return "You cannot do that while sleeping!";
  if (this_player()->GetInCombat() )
       return "You are too busy with combat!";
  if (this_player()->GetParalyzed())
    return "You are paralyzed and can do nothing.";
  if (this_player()->GetStaminaPoints() < 50)
    return "You are too tired.";
  if (this_player()->GetConditionFlag(CONDITION_PREVENT_COMBAT))
    return "Something prevents you from fighting.";
  return 1;
}

mixed do_backstab_liv(object target) {
  object env;
  object who = this_player();
  object *target_enemies;

  target_enemies = target->GetEnemies();

  if(!(env = environment(this_player()))) {
    return "Well, you're boned.";
  }
  if(!target || !present(target, env)) {
    who->eventPrint("Your hapless victim is no longer present.");
    return 1;
  }
  if(member_array(who, target_enemies) != -1) {
    who->eventPrint("%^RED%^You have lost the element of surprise!%^RESET%^");
    return 1;
  }

  who->eventPrint("%^RED%^You sneak up behind " + target->GetName() + "...%^RESET%^");
  who->SetAttack(target, (: eventBackstab, who, target :) );
  return 1;
}

int eventBackstab(object who, object target) {
  object env = environment(who);
  object weapon;
  int chance, pro, con;
  int damage;

  if (!env) return 1;        
  if (!sizeof(who->GetWielded())) {
    who->eventPrint("You need a weapon to do that!");
    return 1;
  }
  weapon = who->GetWielded()[0];
  if (!weapon) return 1;                                                                                          
  damage = who->GetDamage(weapon->GetClass(), "stealth", weapon->GetWeaponType() + " combat");
  damage *= 2;
  // mahkefel: double damage for knives, bows.
  if (weapon->GetWeaponType() == "knife" || weapon->GetWeaponType() == "projectile") {
    damage *= 2;
  }
    
  pro = 20;
  pro += who->GetSkillLevel("stealth")  / 3; 
  pro += who->GetSkillLevel("accuracy") / 4;
  pro += who->GetSkillLevel(weapon->GetWeaponType() + " combat") / 4;
  pro += target->GetSleeping()          * 20; 
  pro += who->GetStatLevel("luck")      / 2;

  con = target->GetStatLevel("luck")   / 2;
  con += target->GetStatLevel("wisdom") / 2;                                                      
  con += target->GetSkillLevel("dodge") / 4;

  if (who->GetTestChar()) debug("backstab base chance: " + pro + " - " + con);
  
  // mahkefel: removed -random(target level), made rand(pro) - rand(con) instead
  // SLIGHTLY weighted towards attacker.
  chance = random(pro) - random(con);
  if (who->GetTestChar()) debug("backstab base damage: " + damage);
  if (who->GetTestChar()) debug("backstab result chance: " + chance);

  who->AddStaminaPoints(-50);
  who->eventMoralAct(-30 * query_sign(target->GetMorality()) || 1);
  // mahkefel 2017: added a non-fumble failure state.
  if (chance < -100) {
    send_messages( ({ "sneak", "trip", "fall" }),
      "$agent_name%^RED%^ $agent_verb up%^RESET%^ on $target_name, but $agent_verb and $agent_verb on $agent_possessive face!",
      who, target, env);
    who->eventCollapse();
    target->SetSleeping(0);
    target->AddEnemy(who);
    return 1;          
  } else if (chance < 0) {
    send_messages( ({ "roll" }),
      "$target_name%^RED%^ $target_verb%^RESET%^ out of the way of $agent_possessive_noun attack at the last second!",
      who, target, env);   
    target->SetSleeping(0);
    target->AddEnemy(who);
    return 1;              
  }   
  if (chance > 1000) chance = 1000;
  switch (chance) {
    case 0..19:
      break;
    case 20..50:
      damage *= 2;
      break;
    case 51..80:
      damage *= 3;
      break;
    case 81..100:
      damage *= 4;
      break;
    case 101..150:
      damage *= 5;
      break;
    case 151..1000:
      damage *= 6;
      break;
    default:
      debug("Broken Backstab Chance of " + chance + " " + identify(who) + " -> " + identify(target));
      break;
    }
  if (target->GetSleeping()) {
    if (who->GetTestChar()) debug(who->GetCapName() + " backstab sleeping target: " + target->GetCapName());
    send_messages( ({ "sneak", "slay" }),
      "$agent_name%^RED%^ $agent_verb%^RESET%^ up on $target_name and $agent_verb $target_objective in $target_possessive sleep!",
      who, target, env);
    target->eventDie(who);
    return 1;
  }
  if (who->GetTestChar()) debug("backstab final dealt damage: " + damage);
  damage = target->eventReceiveDamage(who, weapon->GetDamageType(), damage, 0, target->GetTorso());
  if (who->GetTestChar()) debug("backstab final actual damage: " + damage);
  who->SendCombatMessages(target, damage, weapon, target->GetTorso());
  return 1;
}

