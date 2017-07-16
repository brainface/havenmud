#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Raze the Keep");
  SetTown("Karak");
  SetMissionDescription(
    "Dealer is tired of Sklaag's continuing failures. "
    "He has requested that you personally break the seige. "
    "Kill all defenders within the Keep, especially Lord "
    "Beornwulf himself. "
    );
  SetTitle("the Annihilator of the Keep");
  SetMissionLevel(40, 500);
  SetMissionPriority(65);
  SetReward("120000 XP");
}


int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if ((kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/humancapn"] >= 1) && 
     (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/hsoldier"] >= 7) &&
     (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/mage"] >=1)) {
 	  who->eventPrint("You have killed the defenders of the Keep!");
    who->AddExperience(120000);
    return 1;
  }
 return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Storm the Keep")) return 1;
  return 0;
}
