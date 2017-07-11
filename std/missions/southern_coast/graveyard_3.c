#include <lib.h>
#include <daemons.h>
#include <domains.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Tomb Raider");
  SetTown("Haven");
  SetMissionDescription(
    "This quest may put you in danger.\n"
    "One last creature remains in the Old Cemetery.  Seek out the lady known as "
    "Philia Ravenhair and dispatch of her."
    );
  SetTitle("the Tomb Raider");
  SetMissionLevel(8, 500);
  SetMissionPriority(35);
  SetReward("12500 XP");
}

int CheckCompletedMission(object who) {
  int count = 0;
  mapping kills = STATISTICS_D->GetKills(who->GetKeyName());
  if (kills[SOUTHERN_COAST_AREAS "dw/npc/vamp"]) {
    who->eventPrint("You have staked the heart of Philia Ravenhair.");
    who->AddExperience(12500);
    return 1;
  }
  return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Crypt Keeper")) return 1;
  return 0;
}
