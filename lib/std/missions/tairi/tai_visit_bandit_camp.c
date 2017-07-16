
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Ronin Camp");
  SetTown("Tairi");
  SetMissionDescription(
    "You are assigned a simple quest of exploration. One to "
    "expand your personal horizons and get you more familiar with "
    "the land of Tairi. You must visit the Ronin Camp south of town. "
    "This quest is completed once you set foot within the feared Ronin "
    "Camp."
    );
  SetTitle("the Island Explorer");
  SetMissionLevel(0, 500);
  SetMissionPriority(100);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)), "/domains/tairi/areas/camp") != -1) {
     who->eventPrint("You have found the Ronin Camp. Congratulations!");

     who->AddExperience(500);
     return 1;
    }
  return 0;
}
