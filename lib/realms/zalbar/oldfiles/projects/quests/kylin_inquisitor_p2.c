#include <lib.h>
#include <daemons.h>
#include <domains.h>

inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Kill the Leaders");
  SetTown("Durgoroth");
  SetMissionDescription(
    "You ealier help was invaluable. The leaders within ruins of Durgoroth " 
    "may be trying to gather their forces to mount an attack on us. We must "
    "strike first. Go into Durgoroth and kill at least three of the leaders: "
    "Ereshk the Masterful, Horror Niscronma, Mekrzi the Lich, Ahzrikh, or "
    "Baelrot the Champion of the Pit. May the Lord of Balance bless you." );
  SetTitle("the Daemon Queller");
  SetMissionLevel(175, 500);
  SetMissionPriority(80);
  SetReward("1500000 XP");
}


int CheckCompletedMission(object who) {
  int total = 0;
  int ld1, ld2, ld3, ld4, ld5;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if(kills[FROSTMARCHES_TOWNS "durgoroth/npc/horror"] >= 1) ld1 = 1;
  if(kills[FROSTMARCHES_TOWNS "durgoroth/npc/shaman"] >= 1) ld2 = 1;
  if(kills[FROSTMARCHES_TOWNS "durgoroth/npc/trainer"] >= 1) ld3 = 1;
  if(kills[FROSTMARCHES_TOWNS "durgoroth/npc/necromancer"] >= 1) ld4 = 1;
  if(kills[FROSTMARCHES_TOWNS "durgoroth/npc/fighter"] >= 1) ld5 = 1;

  total = ld1 + ld2 + ld3 + ld4 + ld5;
  if(who->GetTestChar()) debug("total: " + total);
  if (total >= 3) {
    who->eventPrint("You have weakened the leadership of Durgoroth!");
    who->AddExperience(1500000);
    if(who->GetTestChar()) debug("completed: " + total);
    return 1;
  }
  return 0;
}

void AssignMission(object who) {
  object *gideon = ({ });
  gideon = filter(all_inventory(environment(who)), 
          (: living($1) && $1->GetName() == "Gideon" :));
  gideon[0]->eventForce("cast bless on " + who->GetKeyName());
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Invade the Ruins")) return 1;
  if(who->GetMorality() > 500)
     return 1;
  return 0;
}

