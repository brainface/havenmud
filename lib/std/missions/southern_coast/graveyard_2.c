#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Crypt Keeper");
  SetTown("Haven");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "Find the creature which haunts the Crypt at the center of the "
    "Old Cemetery and banish it from this plane."
    );
  SetTitle("the Crypt Keeper");
  SetMissionLevel(5, 500);
  SetMissionPriority(40);
  SetReward("2500 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[SOUTHERN_COAST_AREAS "dw/npc/wraith"]) {
    who->eventPrint("You have banished the wraith.");
    who->AddExperience(2500);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Graveyard Cleanup")) return 1;
  return 0;
}
