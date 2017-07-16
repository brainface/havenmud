#include <lib.h>
inherit LIB_COMBATSTYLE;

static void create() {
  ::create();
  SetStyleName("juego del palo");
  SetTrainingPointCost(20);
  SetStaminaCost(1);
  SetSkills( ([
    "pole attack" : 20,
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
  if (arrayp(target)) target = target[0];
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
   object *wpns = ({ });
	 int num_wpns;
   object rnd_wpn;  

  pro = who->GetCombatStyleLevel("juego del palo");
  pro += who->GetStatLevel("agility")/3;
  pro += who->GetSkillLevel("pole attack");
  defense = who->GetCombatStyleLevel("juego del palo");
  defense += who->GetSkillLevel("pole defense");
  defense += who->GetStatLevel("agility")/3;
  damage = who->GetDamage(weapon->eventStrike(target) + level*2, 
    "pole attack", target->GetSkillLevel("pole defense") );

  who->eventWeaponRound(target, who->GetWielded());
  if (target->eventReceiveAttack(pro, "pole", who, defense)) {
    who->eventTrainCombatStyle("juego del palo", defense);
  if(random(50) <= level) {
    if (random(2)) {
      	hand = "left";
      	leg = "left";
      	}
      	else {
      	hand = "right";
      	lef = "right";
      	}    
    switch(random(15)) {
      case 0:
         send_messages( ({ "pound" }),
            "$agent_name%^MAGENTA%^BOLD%^ $agent_verb %^RESET%^" + 
            "$agent_possessive " + weapon->GetKeyName() + " solidly against " + 
            "$target_possessive_noun " + hand + " hand, causing " +
            "$target_objective to faulter!",
            who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                 damage, 0, target->GetLimb(hand + " hand"));
          target->SetParalyzed(random(2));
          break;
      case 1:
          send_messages( ({ "twirl", "pummel" }),
              "$agent_name%^MAGENTA%^BOLD%^ $agent_verb with grace %^RESET%^" + 
              "and $agent_verb $target_possessive_noun head%^RESET%^, " + 
              "causing $target_objective to feel dizzy!",
              who, target, environment(who) );
              target->eventReceiveDamage(who, weapon->GetDamageType(),
                damage, 0, target->GetLimb("head"));
              who->SetRecoveryTime(random(20));
              break;
      case 2:
     	    send_messages( ({ "thump" }),
            "$agent_name%^MAGENTA%^BOLD%^ $agent_verb %^RESET%^" +
            "$agent_possessive " + weapon->GetKeyName() + " fiercly against " + 
            "$target_possessive_noun " + hand + " hand, causing " +
            "$target_objective to drop $target_possessive weapons!",
            who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                 damage, 0, target->GetLimb(hand + " hand"));          
  				wpns = target->GetWielded();
  				num_wpns = sizeof(wpns);
  				if (sizeof(wpns)) { rnd_wpn = wpns[random(num_wpns)]; }
  				if (rnd_wpn) {        				
  			    rnd_wpn->eventUnequip(target);
  				  rnd_wpn->eventDrop(target);
  				}
  				break;
  	  case 3:
         send_messages( ({ "sweep" }),
            "$agent_name%^MAGENTA%^BOLD%^ $agent_verb %^RESET%^" + 
            "$agent_possessive " + weapon->GetKeyName() + " under " + 
            "$target_possessive_noun legs, causing " +
            "$target_objective to fall over!",
            who, target, environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                 damage, 0, target->GetLimb(leg + " leg"));
          target->SetParalyzed(random(2));
          target->eventCollapse();
          break;      
        default: 
          send_messages( ({ "hammer" }),
            "$agent_name%^MAGENTA%^BOLD%^ $agent_verb %^RESET%^" + 
            "$agent_possessive weapon against " +
            "$target_name with deadly precision.", who, target, 
              environment(who) );
          target->eventReceiveDamage(who, weapon->GetDamageType(),
                damage, 0, target->GetTorso());
          break;
        }
      return 1;
     }
     }
    who->SendMissMessages(target, -1, target->GetRandomLimb());
    who->eventTrainCombatStyle("juego del palo", random(defense) );
  return 1;
}
