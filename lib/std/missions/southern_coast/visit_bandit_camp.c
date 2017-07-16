#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Bandit Camp");
  SetTown("Haven");
  SetMissionDescription(
    "You are assigned a simple quest of exploration. One to "
    "expand your personal horizons and get you more familiar with "
    "the Southern Coast. You must visit the Bandit Camp near Haven Town. "
    "This quest is completed once you set foot within the feared Bandit "
    "Camp west of Haven Town."
    );
  SetTitle("the Explorer");
  SetMissionLevel(0, 500);
  SetMissionPriority(100);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)), "/domains/southern_coast/areas/camp") != -1) {
     who->eventPrint("You have found the Bandit Camp. Congratulations!");

     who->AddExperience(500);
     return 1;
    }
  return 0;
}

