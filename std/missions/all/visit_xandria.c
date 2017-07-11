#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Xandrian Journey");
  SetTown("all");
  SetMissionDescription(
    "You are assigned a quest of exploration. One to "
    "expand your personal horizons and get you more familiar with "
    "the lands far away. You must visit Xandria.\n"
    "This quest is completed once you set foot along its beautiful shores."
    );
  SetTitle("the Distant Traveller");
  SetMissionLevel(100, 500);
  SetReward("500000 XP");
  SetMissionPriority(10);
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)), "/domains/xandria") != -1) {
     who->eventPrint("You have found Xandria. Congratulations!");
     who->AddExperience(500000);
     return 1;
    }
  return 0;
}

/* This mission is the 2nd in a series of "visit" missions. 
 * This one requires you visit an area without benefit of directions. 
 * It is required to have completed the 1st mission in the series first.
 */

int CanGetMission(object who) {
  return 1;
}
