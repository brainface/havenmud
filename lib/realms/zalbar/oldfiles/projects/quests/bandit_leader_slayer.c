#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Bandit Leader");
  SetTown("Haven");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "For this quest, you must enter the bandit camp and slay "
    "the Bandit Leader."
    );
  SetTitle("the Bandit Slayer");
  SetMissionLevel(10, 500);
  SetMissionPriority(65);
  SetReward("10000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[SOUTHERN_COAST_AREAS "camp/npc/leader"]) {
    who->eventPrint("You have slain the Bandit Leader.");
    who->AddExperience(10000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Bandit Slayer")) return 1;
  return 0;
}
