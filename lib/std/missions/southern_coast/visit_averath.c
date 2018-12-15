#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Averath Ferry");
  SetTown("Haven");
  SetMissionDescription(
    "You are assigned a quest of exploration. One to "
    "expand your personal horizons and get you more familiar with "
    "the lands outside the Southern Coast. You must visit Averath.\n"
    "This quest is completed once you set foot along its beautiful shores."
    );
  SetTitle("the Ferry Rider");
  SetMissionLevel(5, 500);
  SetReward("2500 XP");
  SetMissionPriority(40);
}

int CheckCompletedMission(object who) {
  object room;
  
  if (!environment(who)) return 0;
  room = environment(who);
  
  if (vehiclep(room)) return 0;
  
  if (strsrch(base_name(environment(who)), "/domains/averath") != -1) {
      who->eventPrint("You have found Averath. Congratulations!");
      who->AddExperience(2500);
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

