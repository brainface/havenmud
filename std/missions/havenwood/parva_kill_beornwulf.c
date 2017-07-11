#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Raider of the Keep pt 2");
  SetTown("Parva");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "I see you're a nasty one... After proving"
    " yourself by cutting into the forces defending"
    " the keep, the orcs were pleased. They ask"
    " that you return to the keep and take out"
    " Lord Beornwulf once and for all."
    );
  SetTitle("the Destroyer of Hope");
  SetMissionLevel(40, 500);
  SetMissionPriority(65);
  SetReward("100000 XP");
}


int CheckCompletedMission(object who) {
 mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
 if (kills[SOUTHERN_COAST_AREAS "beornwulf_keep/npc/humancapn"] >= 1) {
    who->eventPrint("You have killed the Lord of the Keep!");
    who->AddExperience(100000);
  return 1;
  }
 return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Raider of the Keep pt 1") &&
     (who->GetMorality() < -1000)) return 1;
  return 0;
}
