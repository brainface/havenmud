
#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Defender of the Keep pt 1");
  SetTown("Haven");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "The time has come to test your mettle. Towards"
    " the west end of Haven Road Lord Beornwulf's"
    " keep is besieged by orcish raiders. Go and"
    " aid Lord Beornwulf's men. Kill at least"
    " 6 orcish raiders."
    );
  SetTitle("the Defender of the Keep");
  SetMissionLevel(7, 500);
  SetMissionPriority(65);
  SetReward("20000 XP");
}



int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/osoldier"] >= 6) {
    who->eventPrint("You have aided the defenders of the Keep!");
    who->AddExperience(20000);
  return 1;
  }
 return 0;
}


int CanGetMission(object who) {
  if(who->GetQuestCompleted("Bandit Slayer") &&
     (who->GetMorality() > 1000)) return 1;
  return 0;
}
