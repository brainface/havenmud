#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Platypus Bay");
  SetTown("Haven");
  SetMissionDescription(
    "You are assigned a simple quest of exploration. One to "
    "expand your personal horizons and get you more familiar with "
    "the Southern Coast. You must visit Platypus Bay.\n"
    "This quest is completed once you set foot along its beautiful shores."
    );
  SetTitle("the Vacationer");
  SetMissionLevel(0, 500);
  SetReward("500 XP");
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)), "/domains/southern_coast/areas/meadow") != -1) {
     who->eventPrint("You have found Platypus Bay. Congratulations!");

     who->AddExperience(500);
     return 1;
    }
  return 0;
}

/* This mission is the 2nd in a series of "visit" missions. 
 * This one requires you visit an area without benefit of directions. 
 * It is required to have completed the 1st mission in the series first.
 */

int CanGetMission(object who) {
  if(who->GetQuestCompleted("Bandit Camp")) return 1;
  return 0;
}
