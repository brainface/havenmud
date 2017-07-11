/*  knife combat style */
#include <lib.h>
inherit LIB_COMBATSTYLE;

static void create() {
  ::create();
  SetStyleName("blade dancing");
  SetTrainingPointCost(30);
  SetStaminaCost(2);
  SetSkills( ([
    "knife combat" : 6,
    ]) );
  SetHelp("This style is an artform of handiwork with a knife. "
          "It deals with the motions used for smaller weapons "
          "to get inside of armour and exploit any close combat "
          "advantage.");
}

int eventStyle(object who, int level, mixed target) {
  int pro = 0, defense = 0;
  int damage;
  object *weapons = ({ }), weapon;
  if (arrayp(target)) target = target[0];
  weapons = who->GetWielded();
  if (!sizeof(weapons)) {
       message("system", "You cannot use blade dancing while unarmed!",
        who);
       return 1;
      }
  weapon = weapons[0];
  if (weapon->GetWeaponType() != "knife") {
     message("system", "Your primary weapon must be a knife to blade dance!",
       who);
     return 1;
   }

  pro = who->GetCombatStyleLevel("blade dancing");
  pro += who->GetStatLevel("agility")/3;
  pro += who->GetSkillLevel("knife combat");
  defense = who->GetDefense();
  defense += who->GetStatLevel("agility")/3;
  damage = who->GetDamage(weapon->eventStrike(target) + level, "knife combat", target->GetDefense() );

  who->eventWeaponRound(target, who->GetWielded());
  if (target->eventReceiveAttack(pro, "knife", who, defense)) {
    who->eventTrainCombatStyle("blade dancing", defense);
  if(random(100) <= level) 
    switch(random(20)) {
      case 0:
         send_messages( ({ "drag" }),
            "$agent_name%^RED%^BOLD%^ $agent_verb $agent_possessive " +
            weapon->GetKeyName() + " across $target_possessive_noun " +
            "skin,%^RESET%^ cutting it badly!",
            who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                 damage, 0, target->GetTorso());
          break;
      case 1:
          send_messages( ({ "slit", "exploit" }),
              "$agent_name quickly%^RED%^BOLD%^ $agent_verb%^RESET%^ " +
              "a hole through $target_possessive_noun armour and " +
              "$agent_verb the opening to the fullest!",
              who, target, environment(who) );
              target->eventReceiveDamage(who, weapon->GetDamageType(),
                damage, 0, target->GetTorso());
              break;
      case 2:
          send_messages( ({ "dance", "stab" }),
            "$agent_name $agent_verb around and%^RED%^BOLD%^ " +
            "$agent_verb%^RESET%^ $target_name repeatedly!",
            who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                   damage, 0, target->GetTorso());
          break;
        case 3:
            send_messages( ({ "twirl" }),
              "$agent_name $agent_verb with superb skill before "
             "%^RED%^BOLD%^slashing%^RESET%^ into $target_name.",
             who, target, environment(who) );
           target->eventReceiveDamage(who, weapon->GetDamageType(),
             damage, 0, target->GetTorso());
           break;
        default: 
          send_messages( ({ "slide", "plunge" }),
            "$agent_name $agent_verb to the " +
            (random(2) ? "left" : "right") + " and%^RED%^ " +
            "$agent_verb%^RESET%^ $agent_possessive weapon into " +
            "$target_name.", who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                damage, 0, target->GetTorso());
          break;
        }
      return 1;
     }
    who->SendCombatMessages(target, -1, 0, target->GetRandomLimb());
    who->eventTrainCombatStyle("blade dancing", random(defense) );
  return 1;
}
