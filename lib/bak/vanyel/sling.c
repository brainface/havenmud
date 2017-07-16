/* Slash weapon style. 
 * Heavily modified by Artanis@Haven 02/02/2003
 */

#include <lib.h>
#include <damage_types.h>
inherit LIB_COMBATSTYLE;

static void create() {
  ::create();
  SetStyleName("sword slinging");
  SetTrainingPointCost(22);
  SetStaminaCost(4);
  SetSkills( ([
    "slash attack" : 20,
    "slash defense" : 20,
    ]) );
  SetHelp("This is the skill of famed duellers and skilled warriors. "
          "It's use is only for experienced warriors, but it allows "
          "a measure of extra power and attacking speed to one "
          "trained to know the weaknesses of an opponent.");
}

int eventStyle(object who, int level, mixed target) {
  int dmg, def;
  string tmp;
  int attack = 0, defense = 0;

  if (!sizeof(who->GetWielded())) {
      message("system", 
          "You must be using a slash weapon to use sword slinging.",
         who);
       if(!userp(who)) {
         who->eventForce("set style to none");
       }
       return 1;
      }
  foreach(object weapon in who->GetWielded()) {
        if (weapon->GetWeaponType() != "slash") {
           message("system",
              capitalize(weapon->GetShort() + " is not a slash weapon!"),
               who);
            return 1;
          }
        }

  if (arrayp(target)) target = target[0];
  attack = who->GetCombatStyleLevel("sword slinging");
  attack += who->GetStatLevel("agility")/25;
  attack += who->GetStatLevel("coordination")/25;
  attack += who->GetSkillLevel("slash attack");

  defense = target->GetSkillLevel("slash defense");
  defense -= who->GetSkillLevel("slash defense")/4;
  defense += target->GetStatLevel("coordination")/25;
  defense += target->GetStatLevel("agility")/25;
  defense += target->GetCombatStyleLevel("sword slinging") * 4;

  dmg = who->GetSkillLevel("slash attack");
  def = who->GetSkillLevel("slash defense");
  
  who->eventTrainCombatStyle("sword slinging", attack);
  if (random(attack) < random(defense)) {
    if (!random(who->GetCombatStyleLevel("sword slinging"))) {
       switch(random(14)) {
         case 0:
           send_messages( ({ "lunge", "overextend", "stumble", "are" }),
           "$agent_name%^RED%^BOLD%^ $agent_verb and $agent_verb "
           "$agent_reflexive%^RESET%^, $agent_verb and $agent_verb "
           "stunned!", who, target, environment(who) );
           who->SetParalyzed(1);
           break;
	       case 1:
           send_messages( ({ "attempt","slash","trip","fall"}),
           "$agent_name $agent_verb to%^RED%^BOLD%^ $agent_verb %^RESET%^"
	         "$target_name, but $agent_verb over $agent_reflexive and "
	         "$agent_verb!", who, target, environment(who) );
           who->eventCollapse(1);
	         who->SetParalyzed(1);
           break;	
	       default:
           who->SendMissMessages(target, -1, target->GetRandomLimb());
           break;
         }
      return 1;
      }
     who->SendMissMessages(target, -1, target->GetRandomLimb());
     return 1;
    }
  who->eventWeaponRound(target, who->GetWielded());
  if (dmg <= 25) {
    switch (random(8)) {
      case 0:
         send_messages( ({ "slide", "get" }),
            "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ "
            + (random(2) ? "left" : "right") + " and $agent_verb "
            "in an extra attack!", who, target, environment(who) );
         who->eventWeaponRound(target, who->GetWielded());
         break;
      default:
	     	break;
	      }
    return ;
    } else if (dmg > 25 && dmg <=40) {
      switch (random(12)) {
        case 0:
          send_messages( ({ "slide", "get" }),
             "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ "
             + (random(2) ? "left" : "right") + " and $agent_verb "
             "in an extra attack!", who, target, environment(who) );
          who->eventWeaponRound(target, who->GetWielded());
          break;
        case 1:
           send_messages( ({ "slash" }),
           "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name "
               "%^YELLOW%^wickedly%^RESET%^ in the " +
                (tmp = target->GetRandomLimb()) + ".",
                 who, target, environment(who) );
           target->eventReceiveDamage(who, SLASH, 
                 who->GetDamage(who->GetWielded()[0]->eventStrike(target),         
		       "slash attack") + dmg/6, tmp);
	         break;
	   	  default:
	   	     break;
        }
     return 1;
     }
   else if (dmg > 40 && dmg <=55) {
      switch (random(12)) {
	      case 0:
          send_messages( ({ "slide", "get" }),
            "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ "
            + (random(2) ? "left" : "right") + " and $agent_verb "
            "in an extra attack!", who, target, environment(who) );
            who->eventWeaponRound(target, who->GetWielded());
          break;
        case 1:
           send_messages( ({ "slash" }),
               "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name "
               "%^YELLOW%^wickedly%^RESET%^ in the " +
                (tmp = target->GetRandomLimb()) + ".",
                who, target, environment(who) );
           target->eventReceiveDamage(who, SLASH, 
               who->GetDamage(who->GetWielded()[0]->eventStrike(target),         
		           "slash attack") + dmg/6, tmp);
	         break;	   
        case 2:
	         send_messages( ({ "slice" }),
             "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^deep into the " +
	           (tmp = target->GetRandomLimb()) + " of $target_name with expert "
	           "skill!", who, target, environment(who));
	         target->eventReceiveDamage(who, SLASH,
		         who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			       "slash attack") + dmg/4, tmp);
	         break;
    		default:
     		  break;
      }
      return 1;
    }
    else if (dmg > 55 && dmg <=70) {
      switch (random(14)) {
	case 0:
         send_messages( ({ "slide", "get" }),
             "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ "
               + (random(2) ? "left" : "right") + " and $agent_verb "
             "in an extra attack!", who, target, environment(who) );
          who->eventWeaponRound(target, who->GetWielded());
          break;
        case 1:
           send_messages( ({ "slash" }),
           "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name "
               "%^YELLOW%^wickedly%^RESET%^ in the " +
                (tmp = target->GetRandomLimb()) + ".",
                who, target, environment(who) );
           target->eventReceiveDamage(who, SLASH, 
               who->GetDamage(who->GetWielded()[0]->eventStrike(target),         
		       "slash attack") + dmg/6, tmp);
	   break;	   
        case 2:
	   send_messages( ({ "slice" }),
           "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^deep into the " +
	   (tmp = target->GetRandomLimb()) + " of $target_name with expert "
	   "skill!", who, target, environment(who));
	   target->eventReceiveDamage(who, SLASH,
		who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg/4, tmp);
	   break;
        case 3:
	   send_messages( ({ "twirl","impale" }),
           "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^around " +
	   "$target_name gracefully and%^YELLOW%^BOLD%^ $agent_verb %^RESET%^"
	   "your weapon deeply into $target_possessive chest!",
	   who, target, environment(who));
	   target->eventReceiveDamage(who, PIERCE,
		who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg/2, tmp);
	   break;
    		  default:
     		  break;
      }
       return 1;
      }
   else if (dmg > 70 && dmg <=85) {
      switch (random(15)) {
	case 0:
         send_messages( ({ "slide", "get" }),
             "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ "
               + (random(2) ? "left" : "right") + " and $agent_verb "
             "in an extra attack!", who, target, environment(who) );
          who->eventWeaponRound(target, who->GetWielded());
          break;
        case 1:
           send_messages( ({ "slash" }),
           "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name "
               "%^YELLOW%^wickedly%^RESET%^ in the " +
                (tmp = target->GetRandomLimb()) + ".",
                who, target, environment(who) );
           target->eventReceiveDamage(who, SLASH, 
               who->GetDamage(who->GetWielded()[0]->eventStrike(target),         
		       "slash attack") + dmg/6, tmp);
	   break;	   
        case 2:
	   send_messages( ({ "slice" }),
           "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^deep into the " +
	   (tmp = target->GetRandomLimb()) + " of $target_name with expert "
	   "skill!", who, target, environment(who));
	   target->eventReceiveDamage(who, SLASH,
		who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg/4, tmp);
	   break;
        case 3:
	   send_messages( ({ "twirl","impale" }),
           "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^around " +
           "$target_name gracefully and%^YELLOW%^BOLD%^ $agent_verb %^RESET%^"
	   "your weapon deeply into $target_possessive chest!",
	   who, target, environment(who));
	   target->eventReceiveDamage(who, PIERCE,
		who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg/2, tmp);
	   break;
	case 4:
	   send_messages( ({ "jump","come","tear" }),
	   "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^high into the air, " 
	   "$agent_verb flying down onto $target_name, and%^YELLOW%^BOLD%^ "
	   "$agent_verb %^RESET%^" 
	   "through $target_possessive body with a vicious attack!",
	   who, target, environment(who));
	   target->eventReceiveDamage(who, SLASH,
	   	who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg, tmp);
    		  default:
     		  break;
      }
	return 1;
      }
   else if (dmg > 85 && dmg <= 150) {
      switch (random(18)) {
	case 0:
         send_messages( ({ "slide", "get" }),
             "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ "
               + (random(2) ? "left" : "right") + " and $agent_verb "
             "in an extra attack!", who, target, environment(who) );
          who->eventWeaponRound(target, who->GetWielded());
          break;
        case 1:
           send_messages( ({ "slash" }),
           "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name "
               "%^YELLOW%^wickedly%^RESET%^ in the " +
                (tmp = target->GetRandomLimb()) + ".",
                who, target, environment(who) );
           target->eventReceiveDamage(who, SLASH, 
               who->GetDamage(who->GetWielded()[0]->eventStrike(target),         
		       "slash attack") + dmg/6, tmp);
	   break;	   
        case 2:
	   send_messages( ({ "slice" }),
           "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^deep into the " +
	   (tmp = target->GetRandomLimb()) + " of $target_name with expert "
	   "skill!", who, target, environment(who));
	   target->eventReceiveDamage(who, SLASH,
		who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg/4, tmp);
	   break;
        case 3:
	   send_messages( ({ "twirl","impale" }),
           "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^around " +
	   "$target_name gracefully and%^YELLOW%^BOLD%^ $agent_verb %^RESET%^"
	   "your weapon deeply into $target_possessive chest!",
	   who, target, environment(who));
	   target->eventReceiveDamage(who, PIERCE,
		who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg/2, tmp);
	   break;
	case 4:
	   send_messages( ({ "jump","come","tear" }),
	   "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^high into the air, " 
	   "$agent_verb flying down onto $target_name, and%^YELLOW%^BOLD%^ "
	   "$agent_verb %^RESET%^" 
	   "through $target_possessive body with a vicious attack!",
	   who, target, environment(who));
	   target->eventReceiveDamage(who, SLASH,
	   	who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg, tmp);
	   break;
        case 5:
	   send_messages( ({ "move" }),
	   "$agent_name $agent_verb with lightning speed, striking $target_name "
	   "%^RED%^BOLD%^repeatedly%^RESET%^ with blinding force!",
	   who, target, environment(who));
	   target->eventReceiveDamage(who, SLASH,
	   	who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg+def/10, tmp);
	        who->eventWeaponRound(target, who->GetWielded());
    		  default:
     		  break;
      }
	return 1;
      }
   else if (dmg > 150) {
      switch (random(12)) {
	case 0:
         send_messages( ({ "slide", "get" }),
             "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ "
               + (random(2) ? "left" : "right") + " and $agent_verb "
             "in an extra attack!", who, target, environment(who) );
          who->eventWeaponRound(target, who->GetWielded());
          break;
        case 1:
           send_messages( ({ "slash" }),
           "$agent_name%^YELLOW%^ $agent_verb%^RESET%^ $target_name "
               "%^YELLOW%^wickedly%^RESET%^ in the " +
                (tmp = target->GetRandomLimb()) + ".",
                who, target, environment(who) );
           target->eventReceiveDamage(who, SLASH, 
               who->GetDamage(who->GetWielded()[0]->eventStrike(target),         
		       "slash attack") + dmg/6, tmp);
	   break;	   
        case 2:
	   send_messages( ({ "slice" }),
           "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^deep into the " +
	   (tmp = target->GetRandomLimb()) + " of $target_name with expert "
	   "skill!", who, target, environment(who));
	   target->eventReceiveDamage(who, SLASH,
		who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg/4, tmp);
	   break;
        case 3:
	   send_messages( ({ "twirl","impale" }),
           "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^ around " +
	   "$target_name gracefully and%^YELLOW%^BOLD%^ $agent_verb %^RESET%^"
	   "your weapon deeply into $target_possessive chest!",
	   who, target, environment(who));
	   target->eventReceiveDamage(who, PIERCE,
		who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg/2, tmp);
	   break;
	case 4:
	   send_messages( ({ "jump","come","tear" }),
	   "$agent_name%^YELLOW%^BOLD%^ $agent_verb %^RESET%^high into the air, " 
	   "$agent_verb flying down onto $target_name, and%^YELLOW%^BOLD%^ "
	   "$agent_verb %^RESET%^" 
	   "through $target_possessive body with a vicious attack!",
	   who, target, environment(who));
	   target->eventReceiveDamage(who, SLASH,
	   	who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg, tmp);
	   break;
        case 5:
	   send_messages( ({ "move" }),
	   "$agent_name $agent_verb with lightning speed, striking $target_name "
	   "%^RED%^BOLD%^repeatedly%^RESET%^ with blinding force!",
	   who, target, environment(who));
	   target->eventReceiveDamage(who, SLASH,
	   	who->GetDamage(who->GetWielded()[0]->eventStrike(target),
			"slash attack") + dmg+def/10, tmp);
	        who->eventWeaponRound(target, who->GetWielded());
    		  default:
     		  break;
      }
	return 1;
  }
  else
  { 

        return 1; 
  }
  return 1;
}
