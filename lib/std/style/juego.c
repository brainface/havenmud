#include <lib.h>
inherit LIB_COMBATSTYLE;

static void create() {
  ::create();
  SetStyleName("juego del palo");
  SetTrainingPointCost(20);
  SetStaminaCost(1);
  SetSkills( ([
    "pole combat" : 20,
    ]) );
  SetHelp("This style is a favourite of the Aetarin warriors on Averath. "
          "It deals with the mastery of pole weapons, allowing the "
          "adept to strike with precision, strength and elegance.");
}

int eventStyle(object who, int level, mixed target) {
  int pro = 0, defense = 0;
  int damage;
  string hand;
  string leg;
  object *weapons = ({ }), weapon;
  object *wpns = ({ });
	int num_wpns;
  object rnd_wpn;   
  if (arrayp(target)) target = target[0];
  wpns = target->GetWielded();
  num_wpns = sizeof(wpns);
  weapons = who->GetWielded();
  if (!sizeof(weapons)) {
       message("system", "You cannot use juego del palo while unarmed!",
        who);
       return 1;
      }
  weapon = weapons[0];
  if (weapon->GetWeaponType() != "pole") {
     message("system", "Your primary weapon must be a pole to use juego del "
     "palo", who);
     return 1;
   }
  

  pro = who->GetCombatStyleLevel("juego del palo");
  pro += who->GetStatLevel("agility")/2;
  pro += who->GetSkillLevel("pole combat");
  defense = who->GetCombatStyleLevel("juego del palo");
  defense += who->GetDefense();
  defense += who->GetStatLevel("agility")/2;
  damage = who->GetDamage(weapon->eventStrike(target) + level*1.5, "pole combat", target->GetDefense() );

  who->eventWeaponRound(target, who->GetWielded());
  if (target->eventReceiveAttack(pro, "pole", who, defense)) {
    who->eventTrainCombatStyle("juego del palo", defense);
  if(random(30) <= level) {
    if (random(2)) {
      	hand = "left";
      	leg = "left";
      	}
      	else {
      	hand = "right";
      	leg = "left";
      	}    
    switch(random(6)) {
      case 0:
         send_messages( ({ "pound" }),
            "$agent_name%^MAGENTA%^BOLD%^ $agent_verb%^RESET%^" + 
            " $agent_possessive " + weapon->GetKeyName() + " solidly against " + 
            "$target_possessive_noun " + hand + " hand, causing " +
            "$target_objective to faulter!",
            who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                 damage, 0, target->GetLimb(hand + " hand"));
          target->SetParalyzed(random(10));
          break;
      case 1:
          send_messages( ({ "twirl", "pummel" }),
              "$agent_name $agent_verb with grace and %^MAGENTA%^BOLD%^" + 
              " $agent_verb%^RESET%^ $target_possessive_noun head%^RESET%^, " + 
              "causing $target_objective to feel dizzy!",
              who, target, environment(who) );
              target->eventReceiveDamage(who, weapon->GetDamageType(),
                damage, 0, target->GetLimb("head"));
              target->SetRecoveryTime(random(20));
              break;
      case 2:
     	    send_messages( ({ "thump" }),
            "$agent_name%^MAGENTA%^BOLD%^ $agent_verb%^RESET%^" +
            " $agent_possessive " + weapon->GetKeyName() + " fiercly against " + 
            "$target_possessive_noun " + hand + " hand, causing " +
            "$target_objective to drop $target_possessive weapons!",
            who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                 damage, 0, target->GetLimb(hand + " hand"));            				
  				if (sizeof(wpns)) { rnd_wpn = wpns[random(num_wpns)]; }
  				if (rnd_wpn) {        				
  			    rnd_wpn->eventUnequip(target);
  				  rnd_wpn->eventDrop(target);
  				}
  				break;
  	  case 3:
         send_messages( ({ "sweep" }),
            "$agent_name%^MAGENTA%^BOLD%^ $agent_verb%^RESET%^" + 
            " $agent_possessive " + weapon->GetKeyName() + " under " + 
            "$target_possessive_noun legs, causing " +
            "$target_objective to fall over!",
            who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                 damage, 0, target->GetLimb(leg + " leg"));
          target->SetParalyzed(random(10));
          target->eventCollapse();
          break;      
        default: 
          send_messages( ({ "hammer" }),
            "$agent_name%^MAGENTA%^BOLD%^ $agent_verb%^RESET%^" + 
            " $agent_possessive weapon against " +
            "$target_name with deadly precision.", who, target, 
              environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                damage*3, 0, target->GetTorso());
          break;
        }
      return 1;
     }
     }
    who->SendCombatMessages(target, -1, 0, target->GetRandomLimb());
    who->eventTrainCombatStyle("juego del palo", defense );
  return 1;
}
