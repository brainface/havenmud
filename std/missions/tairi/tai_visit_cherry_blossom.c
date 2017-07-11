#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Cherry Blossom");
  SetTown("Tairi");
  SetMissionDescription(
    "You are assigned a simple quest of exploration. One to "
    "expand your personal horizons and get you more familiar with "
    "the land of Tairi. You must visit Cherry Blossom Park.\n"
    "This quest is completed once you set foot along its beautiful path."
    );
  SetTitle("the Arboretum Visitor");
  SetMissionLevel(0, 500);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)), "/domains/tairi/areas/copse") != -1) {
     who->eventPrint("You have found Cherry Blossom Park. Congratulations!");

     who->AddExperience(500);
     return 1;
    }
  return 0;
}

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Ronin Camp")) return 1;
  return 0;
}
