#include <lib.h>
inherit LIB_ITEM;



mapping Healing = ([ "health" : 10,]);
int HealingDifficulty = 10;
int MinimumHealing = 0;
int StaminaCost = 1;

int SetHealing(mapping healing);
int AddHealing(mapping healing);
int GetHealing(string type);
int SetHealingDifficulty(int diff);
int GetHealingDifficulty();
int SetMinHealing(int minheal);
int GetMinHealing();
int SetStaminaCost(int stamcost);
int GetStaminaCost(int stamcost);

static void create() {
	::create();
}

mixed eventUse(object me, string args) {
   string who, what;
   object victim;
   object array germs;
   if(!args) { return "Use it to do what to whom?"; }
   sscanf(args, "%s %s", what, who);
   if(!what) { return "Use it to do what?"; }
   if(!who) { return "Use it to do what to whom?"; }
   if (!(what == "heal")) { return "Do you mean to use it to heal someone?"; }
   if(!(victim = present(who, environment(me)))) {
      return "Use it on whom?"; }
    if(MinimumHealing > me->GetSkillLevel("healing") ) {
	return "Your healing skill is not high enough!";
   }
/*
   if(StaminaCost > me->GetStaminaPoints()) {
	return "You do not have enough stamina to use this!";
   }
*/
   me->AddStaminaPoints(-StaminaCost);
   if(Healing["health"]) {
	victim->eventHealDamage(Healing["health"]); 
   }
   if(Healing["stamina"]) {
      victim->AddStaminaPoints(Healing["stamina"]);
   }
   if(Healing["mana"]) {
      victim->AddMagicPoints(Healing["magic"]);
   }
   if(Healing["poison"]) {
      victim->AddPoison(-(Healing["poison"]));
   }
   if(Healing["alcohol"]) {
      victim->AddAlcohol(-Healing["alcohol"]);
      if(victim->GetAlcohol() < 0) victim->AddAlcohol(-(victim->GetAlcohol()));
   }
   if(Healing["caffeine"]) {
      victim->AddCaffeine(-Healing["caffeine"]);
      if(victim->GetCaffeine() < 0) victim->AddCaffeine(-(victim->GetCaffeine()));
   }
   if(Healing["bleeding"]) {
      victim->AddBleeding(-Healing["bleeding"]);
      if(victim->GetBleeding() == 0) {
	 victim->eventPrint("You stop bleeding!");
      }
   }
   if(Healing["disease"]) {
      if(intp(Healing["disease"])) {
         germs = filter(all_inventory(victim), (: $1->GetProperty("germ") :) );
         if(germs[0]->GetCureChance() > Healing["disease"]) {
             send_messages( ({ "attempt", "fail" }),
                  "$agent_name $agent_verb to cure diseases in $target_name, "
                  "but $agent_verb.", me, victim, environment(me) );
         }
	 else {
	    send_messages( ({ "cure" }),
		"$agent_name $agent_verb $target_name of " + germs[0]->GetShort() +
		".", me, victim, environment(me));
	    germs[0]->eventDestruct();
 	 }
      }
      else {
	germs = filter(all_inventory(victim), (: $1->GetProperty("germ") :) );
	foreach(object germ in germs) {
		if(germ->GetKeyName() != Healing["disease"]) germs -= ({ germ });
	}
	if(sizeof(germs)) {
	    send_messages( ({ "cure" }),
		"$agent_name $agent_verb $target_name of " + germs[0]->GetShort() +
		".", me, victim, environment(me));
	    germs[0]->eventDestruct();
	}			
      }
   }
   send_messages("heal",
      "$agent_name $agent_verb $target_name.",
      me, victim, environment(me) );
   victim->eventDisplayStatus();
   eventDestruct();
   return 1;
}

int SetHealing(mapping healing) {
	if(Healing = healing) return 1;
        return 0;
}

int AddHealing(mapping healing) {
	if(Healing += healing) return 1;
	return 0;
}

int GetHealing(string type) {
	return (Healing[type]);
}

int SetHealingDifficulty(int diff) {
	return (HealingDifficulty = diff);
}

int GetHealingDifficulty() {
	return HealingDifficulty;
}

int SetMinHealing(int minheal) {
	return (MinimumHealing = minheal);
}

int GetMinHealing() {
	return MinimumHealing;
}

int SetStaminaCost(int stamcost) {
	return (StaminaCost = stamcost);
}

int GetStaminaCost() {
	return StaminaCost;
}