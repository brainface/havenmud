#include <lib.h>
#include <std.h>
#include <daemons.h>
inherit LIB_DAEMON;

private string *Minerals;
private mapping Miners;

void LoadMinerals();   // Load the array of food items to be farmed.
void eventMine(object who, object where);  // Basic heart_beat that controls mining.
string GetMinerals(string location); // Returns a food filename for you.
void RemoveMiner(object);
void AddMiner(object);


static void create() {
	::create();
	SetNoClean(1);
  Miners = ([]);
  Minerals = ({});
	set_heart_beat(6);
	LoadMinerals();
}

void LoadMinerals() {
	Minerals = get_dir(STD_MINING + "/*.c");
	return;
}

string GetMineral() {
	string *food = ({});
	if (!sizeof(Minerals)) LoadMinerals();
	food = Minerals;
	if (!arrayp(food)) error("Non-array Minerals - unexpected lack of data");
	if (!sizeof(food)) return 0;
	return STD_MINING + food[random(sizeof(food))];
}

void heart_beat() {
	foreach(object farmer in keys(Miners)) {
		eventMine(farmer, Miners[farmer]);
	}
}

void eventMine(object who, object where) {
	int skill, result, chance, bonus;
	int skillxp;
	int levelxp;
	object food;
	string foodfile;
	if (!who || !where) {
		map_delete(Miners, who);
		return;
	}
	if (who->GetSleeping() || who->GetParalyzed()) {
		who->eventPrint("You cannot move.");
		map_delete(Miners, who);
		return;
		}
  if (who->GetStaminaPoints() < 50) {
	  who->eventPrint("You are too tired to further mine the land.");
	  map_delete(Miners, who);
	  return;
	  }
  if (where->GetProperty("no mining")) {
		map_delete(Miners, who);
		who->eventPrint("You cannot mine here.");
	  return;
	  }
	if (where->GetClimate() != "underground") {
	  who->eventPrint("You must be underground to mine!");
	  map_delete(Miners, who);
	  return;
	  }	
	if (environment(who) != where) {
		map_delete(Miners, who);
		return;
	}
	if (who->GetInCombat()) {
		who->eventPrint("You can't mine while fighting!");
		map_delete(Miners, who);
		return;
	}
	skill = who->GetSkillLevel("mining");
	result = random(1000);
	who->AddStaminaPoints(-15);
	bonus = where->GetMiningBonus();
	if (!bonus) bonus = 1;
	chance = (skill * 5 + who->GetLuck() + bonus);
      if (who->GetTestChar())
	debug("R: " + result + " C: " + chance);
	if (result < chance) {
		if (!foodfile = where->GetSpecialMineral())
		foodfile = GetMineral();
		if (!foodfile) {
			CHAT_D->eventSendChannel("MINE_D", "error", "No mineral file!");
			return;
		}		
		if (!food = new(foodfile)) {
			CHAT_D->eventSendChannel("MINE_D", "error", "Failed to clone mineral "
			                         "object: " + STD_MINING + foodfile);
			return;
		}
		send_messages("pull", 
		  "$agent_name $agent_verb $target_name from the ground.",
		  who, food, where);
		levelxp = who->GetLevel();
		skillxp = (who->GetSkillLevel("mining") / 5);
		if(levelxp < 15) levelxp = 15;
		if(skillxp < 1) skillxp = 1;
		food->eventMove(who);
		who->AddExperience(food->GetMass() * levelxp * skillxp);
		RemoveMiner(who);
		return;
	}
	send_messages("continue", "$agent_name $agent_verb mining the ground.",
	  who, 0, where);
	return;
}

void RemoveMiner(object who) {
	map_delete(Miners, who);
	return;
}

object *GetMiners() {
	return keys(Miners);
}

int GetMining(object who) {
	if (Miners[who]) return 1;
	return 0;
}

void AddMiner(object who) {
	Miners[who] = environment(who);
	return;
}
