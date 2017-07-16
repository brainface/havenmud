/*  NIIIIIINNNNNNNJJJJJAAAAA!!!!!!! */
#include <lib.h>
#include <position.h>
#include <damage_types.h>
inherit LIB_COMBATSTYLE;

static void create() {
  ::create();
  SetStyleName("ninjitsu");
  SetTrainingPointCost(60);
  SetSkills( ([
     "melee combat" : 20,
    ]) );
  SetStaminaCost(4);
  SetHelp("The art of the ninja is a difficult one to learn, being "
          "a full method of both attack and defense which serves to "
          "teach the student about the weak areas of most targets "
          "and study the most effective ways to stun or otherwise "
          "incapacitate a foe.");
}

varargs int eventStyle(object who, int level, mixed target) {
  int defense = 0, attack = 0;
  object *weapons = who->GetWielded();
  if (arrayp(target)) target = target[0];

  if (sizeof(weapons) == 1) {
    attack = who->GetSkillLevel(weapons[0]->GetWeaponType() + " combat");
    attack += who->GetCombatStyleLevel("ninjitsu");
    attack += who->GetStatLevel("agility");
    attack += who->GetStatLevel("coordination");
    defense = target->GetDefense();
    defense += target->GetStatLevel("agility");
    defense += target->GetStatLevel("coordination");
    }
  if (sizeof(weapons) > 1) {
    attack = who->GetCombatStyleLevel("ninjitsu");
    attack += who->GetStatLevel("agility");
    attack += who->GetStatLevel("coordination");
    defense = target->GetSkillLevel("multi-weapon")/sizeof(weapons);
    foreach(object weapon in weapons) {
      attack += who->GetSkillLevel(weapon->GetWeaponType() + " combat")/
                sizeof(weapons);
      defense += target->GetDefense();
    }
    attack += who->GetSkillLevel("multi-weapon")/sizeof(weapons);
    defense += target->GetStatLevel("agility");
    defense += target->GetStatLevel("coordination");
  }
  if (!sizeof(weapons)) {
    attack = who->GetSkillLevel("melee combat");
    defense = target->GetDefense();
    attack += who->GetCombatStyleLevel("ninjitsu");
    defense += target->GetStatLevel("agility");
    attack += who->GetStatLevel("agility");
    attack += who->GetStatLevel("coordination");
    defense += target->GetStatLevel("coordination");
  }
  
  if (sizeof(weapons)) {
     who->eventWeaponRound(target, weapons);
  }
  if (!sizeof(weapons)) {
      who->eventMeleeRound(target);
  }
    
  if (target->eventReceiveAttack(attack, "melee", who, defense) < 1) {
      who->eventTrainCombatStyle("ninjitsu", attack/20);
    switch (random(10)) {
      case 0:
        send_messages( ({ "leap", "fall" }),
          "$agent_name $agent_verb into the air with deft purpose, "
          "%^RED%^BOLD%^but "
          "$agent_verb flat on $agent_possessive back!"
          "%^RESET%^",
          who, target, environment(who) );
          who->SetPosition(POSITION_LYING);
          return 1;
           break;
      case 1:
          send_messages( ({ "swing", "dodge" }),
            "$agent_name%^RED%^BOLD%^ $agent_verb with fury, "
            "%^RESET%^but $target_name "
            "$target_verb easily.", who, target, environment(who) );
            return 1;
            break;
        case 2:
             send_messages( ({ "attempt", "trip", "fall" }),
               "$agent_name $agent_verb to high-kick $target_name, "
               "%^RED%^BOLD%^but $agent_verb and $agent_verb."
               "%^RESET%^", who, target, environment(who) );
              who->eventCollapse();
              return 1;
               break;
         default:
            who->SendCombatMessages(target, -1, 0, target->GetTorso());            
            return 1;
            break;
      }
  }  
  who->eventTrainCombatStyle("ninjitsu", attack);
  if (random(100) < level) {
    switch(random(5)) {
      case 0:
         send_messages( ({ "leap", "kick" }),
             "$agent_name%^RED%^BOLD%^ quickly $agent_verb%^RESET%^ "
             "and $agent_verb "
            "$target_name in the " + target->GetTorso() + ", knocking "
            "$target_objective to the ground!", who, target, 
             environment(who));
          target->SetPosition(POSITION_LYING);
          target->SetParalyzed(1);
          return 1;
          break;
      case 1:
          send_messages( ({ "make" }),
            "$agent_name $agent_verb a quick and low attack which "
            "%^RED%^BOLD%^"
            "knocks%^RESET%^ $target_name flat!",
             who, target, environment(who) );
          target->SetPosition(POSITION_LYING);
          target->SetParalyzed(1);
          return 1;
          break;
      default:
        send_messages("use",
          "$agent_name $agent_verb $agent_possessive "
          "lightning fast %^RED%^BOLD%^ninjitsu%^RESET%^ skills to "
          "sneak in an "
          "extra attack!", who, target, environment(who) );
         who->eventMeleeRound(target);
         return 1;
          break;
      }
 }
}
