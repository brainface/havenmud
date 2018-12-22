#include <lib.h>
#include <std.h>
#include <position.h>
#include <daemons.h>
#include <vision.h>
inherit LIB_DAEMON;

private string *Minerals;
private mapping Miners;

private mapping Ores = ([]);
void eventReloadOres();

void LoadMinerals();   // Load the array of food items to be farmed.
void eventMine(object who, object where);  // Basic heart_beat that controls mining.
string GetMinerals(string location); // Returns a food filename for you.
void RemoveMiner(object);
void AddMiner(object);

static void create() {
  ::create();
  SetNoClean(1);
  eventReloadOres();
  Miners = ([]);
  Minerals = ({});
  set_heart_beat(6);
  eventReloadOres();
}


void eventReloadOres() {
    string *dirs = ({ });
    string *ores = ({ });

    Ores = ([]);
    dirs = get_dir(STD_MINING + "/");
    foreach(string dir in dirs) {
      ores = get_dir(STD_MINING + "/" + dir + "/*.c");
      if (sizeof(ores)) {
        foreach(string ore in ores) {
          object ob = find_object(STD_MINING + "/" + dir + "/" + ore);
          if( ob ) {
            ob->eventDestruct();
          }
          if (ob = load_object(STD_MINING + "/" + dir + "/" + ore) ) {
            ore = ob->GetKeyName();
            if( ore ) {
                Ores[ore] = ob;
            }
        }
      }
    }
  }
}

object GetOre(string ore) {
    if( !Ores[ore] ) {
        eventReloadOres();
    }
    return Ores[ore];
}

string *GetOres() {
   return (keys(Ores));
}

object GetRandomOre(int skill) {
  object* oresICanFind = ({});
  eventReloadOres();
  skill = 100 + skill * 15; //(50 = 1100, 200 = 4100)
  if (skill < 100) skill = 100;
  foreach (string ore in GetOres()){
    if (Ores[ore]->GetValue() <= skill) {
      oresICanFind += ({Ores[ore]});
    }
  }
  //debug(sizeof(oresICanFind));
  if (!sizeof(oresICanFind)) {
    debug("No ores found while mining! This is an error!");
    return 0;
  }
  return oresICanFind[random(sizeof(oresICanFind))];
}

void heart_beat() {
  foreach(object farmer in keys(Miners)) {
    eventMine(farmer, Miners[farmer]);
  }
}

void eventMine(object who, object where) {
  int skill, result, chance, bonus, i;
  //int skillxp;
  //int levelxp;
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
  if (who->GetPosition() == POSITION_SITTING
    || who->GetPosition() == POSITION_LYING) {
    who->eventPrint("You're going to kneecap yourself if you do that sitting down.");
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

  switch( i = who->GetEffectiveVision() ) {
    case VISION_BLIND:
      map_delete(Miners, who);
      who->eventPrint("You are blind and can see nothing.");
      return;
    case VISION_TOO_DARK:
      map_delete(Miners, who);
      who->eventPrint("It is much too dark to see.");
      return;
    case VISION_DARK:
      map_delete(Miners, who);
      who->eventPrint("It is too dark to see.");
      return;
    case VISION_TOO_BRIGHT:
      map_delete(Miners, who);
      who->eventPrint("It is much too %^YELLOW%^bright%^RESET%^ to see.");
      return;
    case VISION_BRIGHT:
      map_delete(Miners, who);
      who->eventPrint("It is too %^YELLOW%^bright%^RESET%^ to see.");
      return;
    }


  skill = who->GetSkillLevel("mining");

  // make miners run out of minerals.
  if (!where->GetProperty("MinedOut")) {
    where->SetProperty("MinedOut",0);
  } else {
    if ( where->GetProperty("MinedOut") > (skill / 10 - 15)) {
      who->eventPrint("You've stripped " + strip_colours(where->GetShort()) + " bare!");
      map_delete(Miners, who);
      return;
    }
  }

  result = random(1000);
  who->AddStaminaPoints(-15);
  bonus = where->GetMiningBonus();
  if (!bonus) bonus = 1;
  chance = (skill * 5 + who->GetLuck() + bonus);
  if (who->GetTestChar()) debug("R: " + result + " C: " + chance);
  if (result < chance) {
    if (!foodfile = where->GetSpecialMineral())
      foodfile = file_name(GetRandomOre(skill+who->GetLuck()+bonus));
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
    //levelxp = who->GetLevel();
    //skillxp = (who->GetSkillLevel("mining") / 5);
    //if(levelxp < 15) levelxp = 15;
    //if(skillxp < 1) skillxp = 1;
    food->eventMove(who);
    who->AddExperience(food->GetValue() * 5 + random(skill*2));
    where->SetProperty("MinedOut",where->GetProperty("MinedOut")+random(3));
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

