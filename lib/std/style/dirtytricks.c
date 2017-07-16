#include <lib.h>
#include <position.h>
#include <damage_types.h>
inherit LIB_COMBATSTYLE;
inherit LIB_CURRENCY;

static void create() {
  ::create();
  SetStyleName("dirty tricks");
  SetTrainingPointCost(20);
  SetSkills( ([
     "knife combat" : 100,
     "stealth"      : 100,
     "stealing"     : 100,
    ]) );
  SetStaminaCost(2);
  SetHelp("The favored style for most rogues and assassins, this style uses "
          "their knowledge of stealth and stealing combined with knife combat "
          "to their full potential against their foes.");
}


int eventStyle(object who, int level, mixed target) {
  int pro = 0, defense = 0;
  int damage, skill, dur, damage2, ragemod, x2;
  string limb;
  object *currs;
  object *weapons = ({ }), weapon;
  
  skill = who->GetSkillLevel("stealing") * (who->GetCombatStyleLevel("dirty tricks")/100);
  skill += who->GetCombatStyleLevel("dirty tricks")/5;
  dur = who->GetCombatStyleLevel("dirty tricks")/25;
  ragemod = who->GetSkillLevel("combat rage")/10;
  
  if (arrayp(target)) target = target[0];
  weapons = who->GetWielded();
  if (!sizeof(weapons)) {
       message("system", "You cannot use dirty tricks while unarmed!",
        who);
       return 1;
      }
  weapon = weapons[0];
  if (weapon->GetWeaponType() != "knife") {
     message("system", "Your primary weapon must be a knife to use dirty tricks!",
       who);
     return 1;
   }

  if (ragemod > 200) ragemod = 200;
  if (who->GetSkillLevel("combat rage") && ragemod < 1) ragemod = 1;

  pro = who->GetCombatStyleLevel("dirty tricks");
  pro += who->GetStatLevel("agility")/3;
  pro += who->GetSkillLevel("knife combat");
  defense = target->GetDefense()/2;
  defense += target->GetStatLevel("agility")/3;
  damage = who->GetSkillLevel("knife combat");
  damage2 = who->GetSkillLevel("stealth");
  damage += ragemod;
  damage2 += ragemod;
  x2 = weapon->GetClass() * 5.0;
  x2 += who->GetStatLevel("strength")/2.0;
  x2 += who->GetStatLevel("luck")/3.0;
  x2 *= 0.5;
  x2 = (x2 + random(to_int(x2))) / 2.0;
  damage2 = damage2 + x2;
  
  who->eventWeaponRound(target, who->GetWielded());
  if (target->eventReceiveAttack(pro, "knife", who, defense)) {
    who->eventTrainCombatStyle("dirty tricks", pro);
  if (!target->GetLimb("right leg")) {
        limb = "left leg";
        }
        else {
        limb = "right leg";
        } 
  if(random(100) <= level) 
    switch(random(100)) {  
      case 0..25:
       if (skill > defense) {
        currs = target->GetCurrencies();
          foreach(string curr in currs) {
            int x;
            if (!target->GetCurrency(curr)) continue;
            if (!(x = random(target->GetCurrency(curr)/5) + 1)) continue;
            if (x > who->GetSkillLevel("stealing")) x = who->GetSkillLevel("stealing");
            if (x < 1) x = 1;
            target->AddCurrency(curr, -x);
            who->AddCurrency(curr, x);
  who->eventPrint("You manage to steal " + x + " " + curr + " from " + target->GetCapName() + ".");
            }
         send_messages( ({ "slice" }),
            "$agent_name%^RED%^BOLD%^ $agent_verb $agent_possessive " +
            weapon->GetKeyName() + " across $target_possessive_noun " +
            "face,%^RESET%^ barely missing!",
            who, target, environment(who) );
           break;
          }
       if (skill <= defense) {
         send_messages( ({ "slice" }),
            "$agent_name%^RED%^BOLD%^ $agent_verb $agent_possessive " +
            weapon->GetKeyName() + " across $target_possessive_noun " +
            "face,%^RESET%^ barely missing!",
            who, target, environment(who) );
                }
          break;
      case 26..40:
          send_messages( ({ "kick", "" }),
              "$agent_name quickly%^RED%^BOLD%^ $agent_verb%^RESET%^ " +
              "dust into $target_possessive_noun eyes blinding " +
              "$target_objective!",
              who, target, environment(who) );
              target->eventReceiveDamage(who, weapon->GetDamageType(),
                (who->GetDamage(who->GetWielded()[0]->eventStrike(target),
                 "knife combat", target->GetDefense()) + damage)*2, 0, target->GetRandomLimb());
          target->eventBlind(who, random(dur)*3);
              break;
      case 41..50:
          send_messages( ({ "duck", "stab" }),
            "$agent_name $agent_verb down and%^RED%^BOLD%^ " +
            "$agent_verb%^RESET%^ $target_name in the " + limb +
            " causing $target_objective to collapse to the ground!",
            who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
           (who->GetDamage(who->GetWielded()[0]->eventStrike(target),
              "knife combat", target->GetDefense()) + damage)*2, 0, target->GetRandomLimb());
          target->SetParalyzed(random(dur)*2);
          target->eventCollapse();
          break;
        case 51..70:
            send_messages( ({ "blur", "slash" }),
              "$agent_possessive_noun movement $agent_verb as $agent_name "
             "repeatedly%^RED%^BOLD%^ $agent_verb%^RESET%^ $target_possessive_noun body.",
             who, target, environment(who) );
           target->eventReceiveDamage(who, weapon->GetDamageType(),
             (who->GetDamage(who->GetWielded()[0]->eventStrike(target),
            "knife combat", target->GetDefense()) + damage)*2, 0, target->GetRandomLimb());
           who->eventWeaponRound(target, who->GetWielded());
           break;
        case 71..85:
          send_messages( ({ "twist", "stab" }),
            "$agent_name $agent_verb to the " +
            (random(2) ? "left" : "right") + " and%^RED%^BOLD%^ " +
            "$agent_verb%^RESET%^ $target_name deeply in the chest causing "
            "$target_objective to bleed.",
            who, target, environment(who) );
           target->eventReceiveDamage(who, weapon->GetDamageType(),
             (who->GetDamage(who->GetWielded()[0]->eventStrike(target),
             "knife combat", target->GetDefense()) + damage)*2, 0, target->GetTorso());
           target->AddBleeding(dur*2);
           break;
        default: 
          send_messages( ({ "slip", "stab" }),
            "$agent_name $agent_verb into the shadows and" 
            "%^RED%^ $agent_verb%^RESET%^ $target_name hard in the " +
            "back.", who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                (who->GetDamage(damage2/2,
               "stealth", target->GetDefense()) + damage2)*2, 0, target->GetTorso());
          break;
        }
      return 1;
     }
    who->SendCombatMessages(target, -1, 0, target->GetRandomLimb());
    who->eventTrainCombatStyle("dirty tricks", pro );
  return 1;
}
