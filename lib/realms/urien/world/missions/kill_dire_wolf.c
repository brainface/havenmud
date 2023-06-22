// 22JUN2023 Urien@Haven 
// Kill Dire Wolves Quest

#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Dire Wolf Slayer");
  SetTown("World");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "For this quest, you must enter the bandit camp and slay "
    "the Bandit Leader."
    );
  SetTitle("the Dire Wolf Slayer");
  SetMissionLevel(20, 500);
  SetMissionPriority(20);
  SetReward("10000 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[WORLD_NPC "dire_wolf"]) {
    who->eventPrint("You have reduced the dire wolf threat.");
    who->AddExperience(10000);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Bandit Slayer")) return 1;
  return 0;
}
