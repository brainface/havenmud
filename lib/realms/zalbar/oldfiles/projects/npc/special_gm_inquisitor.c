#include <lib.h>
#include <damage_types.h>
#include "../outpost.h"

inherit LIB_SENTIENT;

void DoSomething();
void DoCombatSomething();
int hitCallback(object who, object agent, int dmg, class MagicProtection cl);
void endCallback(object who);
class MagicProtection protection;


static void create() {
  sentient::create();
  SetKeyName("atariel Banewulf");
  SetId( ({ "grand master", "kylin invader", "inquisitor", "atariel",
  					"atariel banewulf" }) );
  SetAdjectives( ({"kylin", "grand", "inquisitor", "master"}) );
  SetReligion("Kylin");
  SetShort("Grand Master Atariel Banewulf, Inquisitor of Kylin");
  SetRace("elf");
  SetFriends( ({ "kylin invader", "inquisitor" }) );
  SetClass("cleric");
  SetClass("cavalier");
  SetStat("wisdom",40,1);
  SetSkill("fire magic",1,2);
  SetLevel(225);
  SetMorality(3000);
  SetGender("female");
  SetLong("Grand Master Atariel Banewulf stands six feet tall with long black hair which "
  				"hangs to the middle of her back. Her beauty is reknown around Kailie "
  				"just as much as her faith in her Lord, Duuktsaryth. She has turned her "
  				"back on her family to strive for his high position within the Kylin "
  				"church, and she is the youngest elf to attain the position of "
  				"Grand Master Inquisitor." );
  SetInventory( ([
     OP_OBJ + "chain_armour"  : "wear armour",
     OP_OBJ + "flame_rapier"  : "wield rapier",
     OP_OBJ + "kylin_surcoat" : "wear surcoat",
     ]) );
  SetCurrency("imperials",random(2000) + 200);
  SetAction(99, (: DoSomething :) );
  SetCombatAction(60, (: DoCombatSomething :));
  SetSpellBook( ([
     "superior wall of force" : 100,
     "hand of judgement"      : 100,
     "divine power"           : 100,
     "clarity of thought"     : 100,
     "perfect recovery"       : 100,
     ]) );
   SetFirstCommands( ({ 
  	"cast divine power",
    }) );
}

void DoSomething() {
	object who = this_object();
	
	who->AddMagicProtections(protection);
	
	
	
	/*
	if(!GetProperty("divine power")) {
		eventCast(divine power");
		return;
	}
        
  if ((sizeof(GetMagicProtection()) < 3)) {
  	eventForce("cast superior wall of force" );
  	return;
  }*/
}

void DoCombatSomething() {
	object target = GetCurrentEnemy();
	object who = this_object();

	if(who->GetRecoveryTime() > 500) { 
		eventForce("cast clarity of thought");
		return;
	}
		 
  if((sizeof(GetMagicProtection())) < 3) {
  	eventForce("cast superior wall of force");
  	return;
  }
  
  if((who->GetHealthPoints()) < ((who->GetMaxHealthPoints())/2)) {
  	eventForce("cast perfect recovery");
  	return;
  }
  
  switch(random(6)) {
  	case 0:
  		if(target->GetUndead(1))
  			eventForce("cast perfect recovery on " + target->GetKeyName());
  		break;
  	default:
  		eventForce("cast hand of judgement on " + target->GetKeyName());
  		break;
  	}
}  	

class MagicProtection {
	
  debug("Divine Protections 1");
  protection = new(class MagicProtection); 
  protection->name = "divine protection";
  protection->bits = ALL_EXTERNAL;
  protection->end = (: endCallback :);
  protection->hit = (: hitCallback :);
  protection->caster = this_object();
  protection->time    = 250 * 100/10; 
  protection->protect = 250 * 100;
  protection->limit = 2;
  protection->args = 100;
  debug("Divine Protections 2");
  debug("Time = " + protection->time + " Amount = " +  protection->protect + " SL: " + GetSpellLevel());
  if(target->AddMagicProtection(protection)){
    send_messages("appear",
                   "$target_name $target_verb %^BLUE%^divinely protected%^RESET%^ by the Lord of Balance.",
                   who, targets[0],environment(who));
  return 1;
  }
    debug("Divine Protections 3");
}

int hitCallback(object who, object agent, int dmg, class MagicProtection cl) {
  if (who == agent) return 0;  
  send_messages("", 
      "The %^YELLOW%^divine protection%^RESET%^ surrounding "
      "$agent_name responds to $target_possessive attacks.",
       who, agent, environment(who) );
    
  return dmg;
  }  
  
void endCallback(object who) {
    if(who) {
      send_messages("", "The %^BOLD%^BLUE%^divine protections%^RESET%^ around"
        " $agent_name ceases to exist.",
        who, 0, environment(who));
    }
}

