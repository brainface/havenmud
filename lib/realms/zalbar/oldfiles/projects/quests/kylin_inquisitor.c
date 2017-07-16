#include <lib.h>
#include <daemons.h>
#include <domains.h>

inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Invade the Ruins");
  SetTown("Durgoroth");
  SetMissionDescription(
    "You have decided to help the Inquisitors purge the "
    "chaotic daemons from the ruins of Durgoroth. Go into "
    "the foul ruins of Durgoroth and kill ten of the "
    "daemon survivors within those walls. May the Lord of "
    "Balance bless you." );
  SetMissionLevel(150, 500);
  SetMissionPriority(80);
  SetReward("1000000 XP");
}


int CheckCompletedMission(object who) {
  int total = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());

  total += kills[FROSTMARCHES_TOWNS "durgoroth/npc/weakcitizen"];
  total += kills[FROSTMARCHES_TOWNS "durgoroth/npc/toughcitizen"];
  total += kills[FROSTMARCHES_TOWNS "durgoroth/npc/toughcitizen2"];
  
  if(total >= 10) {
    who->eventPrint("You have weakened the daemon horde within Durgoroth!");
    who->AddExperience(1000000);
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
  if (who->GetMorality() > 500)
     return 1;
  return 0;
}
