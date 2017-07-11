
#include <lib.h>
inherit LIB_MISSION;

static void create() {
  ::create();
  SetMissionName("Haven Ferry");
  SetTown("Averath");
  SetMissionDescription(
    "You are assigned a quest of exploration. One such as yourself"
    " should become more familiar with the lands across the seas."
    " Take a ferry ride to Haven Town, the most central city in"
    " the known world."
    );
  SetTitle("the Averan Ferry Rider");
  SetMissionLevel(5, 500);
  SetReward("2500 XP");
  SetMissionPriority(40);
}

int CheckCompletedMission(object who) {
  if (strsrch(base_name(environment(who)), "/domains/southern_coast/towns/haven") != -1) {
     who->eventPrint("You have found Haven Town. Congratulations!");
     
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
