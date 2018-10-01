/* Sword Slinging
 * Aerelus (11/14/2007)
*/

#include <lib.h>
#include <damage_types.h>
inherit LIB_COMBATSTYLE;

void sendHitMessage(object who, mixed target, int level, int damage, string limb);
void sendFailMessage(object who, mixed target);

static void create() {
  ::create();
  SetStyleName("sword slinging");
  SetTrainingPointCost(20);
  SetStaminaCost(15);
  SetSkills( ([
    "slash combat" : 40,
    ]) );
  SetHelp("This is the skill of famed duellers and skilled warriors. "
    "It's use is only for experienced warriors, but it allows "
    "a measure of extra power and attacking speed to one "
    "trained to know the weaknesses of an opponent.");
}

int eventStyle(object who, int level, mixed target) {
  int pro = 0, defense = 0, attacks = 0;
  int damage, chance; 
  string limb; 
  object *weapons = ({ }), weapon;
  
  if (arrayp(target)) target = target[0];
  weapons = who->GetWielded();
  
  if (!sizeof(weapons)) {
  	who->eventPrint("You must be using a slash weapon to use sword slinging.");  	
  	return 1;
  }
  
  foreach(weapon in weapons) {
    if (weapon->GetWeaponType() != "slash") {
    	who->eventPrint("You must be using a slash weapon to use sword slinging.");    	
    	return 1;
    }  	
  }
  
  pro = level;
  pro += who->GetStatLevel("coordination")/3;
  pro += who->GetSkillLevel("slash combat");
  defense = who->GetDefense();
  defense += who->GetStatLevel("agility")/3;
  weapon = weapons[0];
  damage = who->GetDamage(weapon->eventStrike(target) + level, "slash combat", target->GetDefense() );
  damage += (level * (8 + random(who->GetSkillLevel("slash combat")/50)));
  who->eventWeaponRound(target, who->GetWielded());  
  chance = random(115);  
  
  if (level > chance) {  	
    who->eventTrainCombatStyle("sword slinging", defense);
    limb = target->GetRandomLimb();        
    target->eventReceiveDamage(who, weapon->GetDamageType(), damage, 0, limb);
    weapon->eventReceiveDamage(who, BLUNT, damage/10, 0, limb); 
    sendHitMessage(who, target, level, damage, limb);    
  }
  else {
  	who->eventTrainCombatStyle("sword slinging", defense/2);
  	sendFailMessage(who, target);
  }  	
  
  who->SendCombatMessages(target, -1, 0, limb);
  return 1;
} 	 

void sendHitMessage(object who, object target, int level, int damage, string limb) { 
  int x, rnd, lvl;
  string dir;   
  x = random(1);  
  rnd = random(10);
  lvl = level + random(100);
  if (lvl <= 50) {   
    switch(x) {
      case 0:
        send_messages(({ "strike", "slice" }),
           "$agent_name $agent_verb with precision, and%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ $agent_possessive " + 
           "weapon across $target_possessive_noun " + limb + ".",
           who, target, environment(who));
        break;
      case 1:
        send_messages(({ "thrust" }),
          "$agent_name%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ $agent_possessive weapon into $target_possessive_noun " + 
          limb + ", causing $target_objective to wince in pain.",
          who, target, environment(who));       
        break;
    }
    return;       
  }
  
  if (lvl <= 100) {
  	x = random(1);     	  
    switch(x) {
      case 0:       
        send_messages(({ "glare", "notice", "slash" }),
        "$agent_name $agent_verb at $target_name with hostile intent, and $agent_verb " + 
        "an opening in $target_possessive defense. " + capitalize("$agent_name") + " elegantly%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ " + 
        "$agent_possessive weapon across $target_possessive_noun " + limb + ".",
        who, target, environment(who));   
        break;
      case 1:                
        send_messages(({ "dive", "slice" }),
        "$agent_name $agent_verb to the left with great speed, and%^YELLOW%^BOLD%^ $agent_verb%^RESET%^ " + 
        "$target_possessive_noun " + limb + " with $agent_possessive weapon.",
        who, target, environment(who));       
        break;
    }
    return;   
  }
  
  if (lvl <= 150) { 
  	x = random(1);    	
    switch(x) {
      case 0:       
        send_messages(({ "twirl", "slice" }),
        "$agent_name $agent_verb gracefully and%^RED%^BOLD%^ $agent_verb deeply%^RESET%^ into "
        "$target_possessive_noun " + limb + " with $agent_possessive weapon.",
        who, target, environment(who));
        break;
      case 1:       
        send_messages(({ "swing", "force" }),
        "$agent_name $agent_verb $agent_possessive weapon towards $target_name " + 
        "in desperation, and%^RED%^BOLD%^ $agent_verb%^RESET%^ it into $target_possessive " + limb + 
        " with expertise.",
        who, target, environment(who));
        break;
    }
    return;   
  }
    
  if (rnd == 7) {     
    send_messages(({ "drive" }),
    "$agent_name%^RED%^BOLD%^ $agent_verb $agent_possessive weapon deeply%^RESET%^ into " + 
    "$target_possessive_noun " + limb + ",%^YELLOW%^BOLD%^ causing it to bleed%^RESET%^!",
    who, target, environment(who));
    target->AddBleeding(level/8);
    return;
  }
      
  x = random(1);  
  switch(x) {  	
    case 0:       
      send_messages(({ "drive" }),
      "$agent_name effortlessly%^RED%^BOLD%^ $agent_verb $agent_possessive " + 
      "weapon deeply%^RESET%^ into $target_possessive_noun " + limb + ".",
      who, target, environment(who));
    break;
    case 1:       
      send_messages(({ "slash" }),
      "$agent_name gracefully%^RED%^BOLD%^ $agent_verb $agent_possessive " + 
      "weapon deeply%^RESET%^ across $target_possessive_noun " + limb + ".",
      who, target, environment(who));
    break;
  }  
  return;
}   

void sendFailMessage(object who, object target) {
  int x;
  x = random(3);  
  
  switch(x) {
    case 0:
      send_messages(({ "attempt", "slice", "fail" }),
           "$agent_name $agent_verb to $agent_verb $target_possessive_noun " + 
           target->GetRandomLimb() + ", but $agent_verb miserably.",
           who, target, environment(who));
      break;
    case 1:
      send_messages(({ "attempt", "slash", "trip", "fail" }),
           "$agent_name desperately $agent_verb to $agent_verb " + 
           "$target_possessive_noun " + target->GetRandomLimb() + ", but "
           "$agent_verb over $agent_possessive own foot and $agent_verb.", 
           who, target, environment(who));
      break;
    case 2:
      send_messages(({ "twirl", "thrust" }),
           "$agent_name $agent_verb around gracefully, and $agent_verb " + 
           "$agent_possessive weapon towards $target_name with determination, " +
           "only to miss completely.",
           who, target, environment(who));
      break;
    case 3:
      send_messages(({ "attempt", "impale", "hit" }),
           "$agent_name $agent_verb to $agent_verb $target_possessive_noun " + 
           target->GetRandomLimb() + ", but $agent_verb nothing but thin air.",
           who, target, environment(who));
      break;
  } 
  return;
}
  